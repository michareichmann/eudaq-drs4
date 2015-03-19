// EUDAQ includes:
#include "eudaq/Producer.hh"
#include "eudaq/Logger.hh"
#include "eudaq/RawDataEvent.hh"
#include "eudaq/Timer.hh"
#include "eudaq/Utils.hh"
#include "eudaq/OptionParser.hh"
#include "eudaq/Configuration.hh"

#include "DRS4Producer.hh"

// system includes:
#include <iostream>
#include <ostream>
#include <vector>
#include <mutex>
#include <string>

static const std::string EVENT_TYPE = "DRS4";

DRS4Producer::DRS4Producer(const std::string & name, const std::string & runcontrol, const std::string & verbosity)  : eudaq::Producer(name, runcontrol),
m_run(0),
m_ev(0),
m_producerName(name),
m_event_type("DRS4"){

}

void DRS4Producer::OnStartRun(unsigned runnum_ber) {

};
void DRS4Producer::OnStopRun() {

    std::cout << "Start Run: " << m_run << std::endl;

    eudaq::RawDataEvent bore(eudaq::RawDataEvent::BORE(m_event_type, m_run));
    bore.SetTag("DRS4_BOARD", std::to_string(m_b->GetBoardSerialNumber()));

    // Set the PCB mount type for correct coordinate transformation:
    bore.SetTag("DRS4_FW", std::to_string(m_b->GetFirmwareVersion()));

    // Send the event out:
    SendEvent(bore);

    std::cout << "BORE for DRS4 Board: (event type"<<m_event_type<<")"<<endl;

	/* Start Readout */
	m_b->StartDomino();
};

void DRS4Producer::OnTerminate() {};

void DRS4Producer::ReadoutLoop() {
	while (!m_terminated) {
		// No run is m_running, cycle and wait:
		if(!m_running) {
			// Move this thread to the end of the scheduler queue:
			sched_yield();
			continue;
		}
		else {
			// Acquire lock for pxarCore object access:
			m_b->SoftTrigger();
			if (m_b->IsBusy())
				continue;
			// Trying to get the next event, daqGetRawEvent throws exception if none is available:
			try {
				/* read all waveforms */
				m_b->TransferWaves(0, 8);

				/* read time (X) array of first channel in ns */
				m_b->GetTime(0, 0, m_b->GetTriggerCell(0), time_array[0]);

				/* decode waveform (Y) array of first channel in mV */
				m_b->GetWave(0, 0, wave_array[0]);

				/* read time (X) array of second channel in ns
				   Note: On the evaluation board input #1 is connected to channel 0 and 1 of
				   the DRS chip, input #2 is connected to channel 2 and 3 and so on. So to
				   get the input #2 we have to read DRS channel #2, not #1. */
				m_b->GetTime(0, 2, m_b->GetTriggerCell(0), time_array[1]);

				/* decode waveform (Y) array of second channel in mV */
				m_b->GetWave(0, 2, wave_array[1]);

				/* Restart Readout */
				m_b->StartDomino();

				/* print some progress indication */
				printf("\rEvent #%6d read successfully\n",m_ev);

				eudaq::RawDataEvent ev(m_event_type, m_run, m_ev);
//
//				  float time_array[8][1024];
//				  float wave_array[8][1024];
				ev.AddBlock(0, reinterpret_cast<const char*>(&time_array[0]), sizeof( time_array[0][0])*8*1024);
				ev.AddBlock(0, reinterpret_cast<const char*>(&wave_array[0]), sizeof( wave_array[0][0])*8*1024);

				SendEvent(ev);
				m_ev++;
//				if(daqEvent.data.size() > 1) { m_ev_filled++; m_ev_runningavg_filled++; }

				if(m_ev%1000 == 0) {
					std::cout << "DRS4 Board "
							<< " EVT " << m_ev << std::endl;
				}
			}
			catch(int e) {
				// No event available in derandomize buffers (DTB RAM), return to scheduler:
				cout << "An exception occurred. Exception Nr. " << e << '\n';
				sched_yield();
			}
		}
	}
};

void DRS4Producer::OnConfigure(const eudaq::Configuration& conf) {

	m_config = conf;
	/* do initial scan */
	m_drs = new DRS();

	/* show any found board(s) */
	for (size_t i=0 ; i<m_drs->GetNumberOfBoards() ; i++) {
		m_b = m_drs->GetBoard(i);
		printf("Found DRS4 evaluation board, serial #%d, firmware revision %d\n",
				m_b->GetBoardSerialNumber(), m_b->GetFirmwareVersion());
	}

	/* exit if no board found */
	int nBoards = m_drs->GetNumberOfBoards();

	/* continue working with first board only */
	m_b = m_drs->GetBoard(0);


	/* initialize board */
	m_b->Init();

	/* set sampling frequency */
	m_b->SetFrequency(5, true);

	/* enable transparent mode needed for analog trigger */
	m_b->SetTranspMode(1);

	/* set input range to -0.5V ... +0.5V */
	m_b->SetInputRange(0);

	/* use following line to set range to 0..1V */
	//b->SetInputRange(0.5);

	/* use following line to turn on the internal 100 MHz clock connected to all channels  */
	m_b->EnableTcal(1);

	/* use following lines to enable hardware trigger on CH1 at 50 mV positive edge */
	if (m_b->GetBoardType() >= 8) {        // Evaluation Board V4&5
		m_b->EnableTrigger(1, 0);           // enable hardware trigger
		m_b->SetTriggerSource(1<<0);        // set CH1 as source
	} else if (m_b->GetBoardType() == 7) { // Evaluation Board V3
		m_b->EnableTrigger(0, 1);           // lemo off, analog trigger on
		m_b->SetTriggerSource(0);           // use CH1 as source
	}
	m_b->SetTriggerLevel(-0.05);            // 0.05 V
	m_b->SetTriggerPolarity(false);        // positive edge
}


int main(int /*argc*/, const char ** argv) {
	// You can use the OptionParser to get command-line arguments
	// then they will automatically be described in the help (-h) option
	eudaq::OptionParser op("DRS4 Producer", "0.0",
			"Run options");
	eudaq::Option<std::string> rctrl(op, "r", "runcontrol",
			"tcp://localhost:44000", "address", "The address of the RunControl.");
	eudaq::Option<std::string> level(op, "l", "log-level", "NONE", "level",
			"The minimum level for displaying log messages locally");
	eudaq::Option<std::string> name (op, "n", "name", "DRS4", "string",
			"The name of this Producer");
	eudaq::Option<std::string> verbosity(op, "v", "verbosity mode", "INFO", "string");
	try {
		// This will look through the command-line arguments and set the options
		op.Parse(argv);
		// Set the Log level for displaying messages based on command-line
		EUDAQ_LOG_LEVEL(level.Value());
		// Create a producer
		DRS4Producer producer(name.Value(), rctrl.Value(), verbosity.Value());
		// And set it running...
		producer.ReadoutLoop();
		// When the readout loop terminates, it is time to go
		std::cout << "Quitting" << std::endl;
	} catch (...) {
		// This does some basic error handling of common exceptions
		return op.HandleMainException();
	}
	return 0;
}