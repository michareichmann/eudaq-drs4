/*
 * WaveformCollection.cc
 *
 *  Created on: Jun 16, 2011
 *      Author: stanitz
 */

#include "WaveformCollection.hh"
#include "OnlineMon.hh"

static int counting = 0;
static int events = 0;

bool WaveformCollection::isWaveformRegistered(SimpleStandardWaveform p)
{
	std::map<SimpleStandardWaveform,WaveformHistos*>::iterator it;
	it = _map.find(p);
	return (it != _map.end());
}

void WaveformCollection::fillHistograms(const SimpleStandardWaveform &simpWaveform)
{

	if (!isWaveformRegistered(simpWaveform))
	{
		registerWaveform(simpWaveform);
		isOneWaveformRegistered = true;
	}

	WaveformHistos *Waveform = _map[simpWaveform];
	Waveform->Fill(simpWaveform);

	++counting;

}

void WaveformCollection::bookHistograms(const SimpleStandardEvent &simpev)
{
	for (int Waveform = 0; Waveform < simpev.getNWaveforms(); Waveform++)
	{
		SimpleStandardWaveform simpWaveform = simpev.getWaveform(Waveform);
		if (!isWaveformRegistered(simpWaveform))
		{
			registerWaveform(simpWaveform);
		}
	}
}


void WaveformCollection::Write(TFile *file)
{
	if (file==NULL)
	{
		//cout << "WaveformCollection::Write File pointer is NULL"<<endl;
		exit(-1);
	}
	if (gDirectory!=NULL) //check if this pointer exists
	{
		gDirectory->mkdir("Waveforms");
		gDirectory->cd("Waveforms");


		std::map<SimpleStandardWaveform,WaveformHistos*>::iterator it;
		for (it = _map.begin(); it != _map.end(); ++it) {

			char sensorfolder[255] = "";
			sprintf(sensorfolder,"%s_%d",it->first.getName().c_str(), it->first.getID());
			//cout << "Making new subfolder " << sensorfolder << endl;
			gDirectory->mkdir(sensorfolder);
			gDirectory->cd(sensorfolder);
			it->second->Write();

			//gDirectory->ls();
			gDirectory->cd("..");
		}
		gDirectory->cd("..");
	}
}

void WaveformCollection::Calculate(const unsigned int currentEventNumber)
{
	//	cout<<"WaveformCollection::Calculate"<< currentEventNumber<<" "<<_reduce<<" "<< (currentEventNumber % 1000*_reduce == 0)<<endl;
	if (( true))//currentEventNumber % _reduce == 0))
	{
		std::map<SimpleStandardWaveform,WaveformHistos*>::iterator it;
		for (it = _map.begin(); it != _map.end(); ++it)
		{
			//			std::cout << "WaveformCollection::Calculating "<< currentEventNumber<<std::endl;
			it->second->Calculate(currentEventNumber/_reduce);
		}
	}
}

void WaveformCollection::Reset()
{
	std::map<SimpleStandardWaveform,WaveformHistos*>::iterator it;
	for (it = _map.begin(); it != _map.end(); ++it)
	{
		(*it).second->Reset();
	}
}


void WaveformCollection::Fill(const SimpleStandardEvent &simpev)
{
//	cout<<"WaveformCollection::Fill\t"<<simpev.getNPlanes()<<" "<<simpev.getNWaveforms()<<endl;
	for (int Waveform = 0; Waveform < simpev.getNWaveforms(); Waveform++) {
		const SimpleStandardWaveform&  simpWaveform = simpev.getWaveform(Waveform);
//		cout<<Waveform<<"\t"<<simpWaveform.getChannelName()<<endl;
		fillHistograms(simpWaveform);
	}

}

void WaveformCollection::registerWaveform(const SimpleStandardWaveform &p) {
//	cout<<"WaveformCollection::registerWaveform \t\""<<p.getName()<<"\" "<<p.getID()<<" \""<<p.getChannelName()<<"\" mon:"<<_mon<<endl;
	WaveformHistos *tmphisto = new WaveformHistos(p,_mon);
	tmphisto->SetOptions(_WaveformOptions);
	_map[p] = tmphisto;
	//std::cout << "Registered Waveform: " << p.getName() << " " << p.getID() << std::endl;
	//WaveformRegistered(p.getName(),p.getID());
	if (_mon != NULL)
	{
		if (_mon->getOnlineMon()==NULL)
		{
			return; // don't register items
		}
//		cout << "WaveformCollection:: Monitor running in online-mode" << endl;
		char tree[1024], folder[1024];

		sprintf(tree,"%s/Ch %i - %s/MinVoltage",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getMinVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/MaxVoltage",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getMaxVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/DeltaVoltage",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getDeltaVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/FullIntegral",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getFullIntegralVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/SignalIntegral",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getSignalIntegralVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/PedestalIntegral",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getPedestalIntegralVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/DeltaIntegral",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getDeltaIntegralVoltageHisto(), "",0);

		sprintf(tree,"%s/Ch %i - %s/DeltaVoltageProfile",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getProfileDeltaVoltage(), "",0);

		sprintf(tree,"%s/Ch %i - %s/DeltaIntegralProfile",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getProfileDeltaIntegral(), "",0);
//
		sprintf(tree,"%s/Ch %i - %s/RawWaveform",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHisto(tree,getWaveformHistos(p.getName(),p.getID())->getWaveformGraph(0), "L",0);

		sprintf(tree,"%s/Ch %i - %s/RawWaveformStack",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
		_mon->getOnlineMon()->registerTreeItem(tree);
		_mon->getOnlineMon()->registerHistoStack(tree,getWaveformHistos(p.getName(),p.getID())->getWaveformStack(), "nostack",0);

		sprintf(folder,"%s",p.getName().c_str());
#ifdef DEBUG
		cout << "DEBUG "<< p.getName().c_str() <<endl;
		cout << "DEBUG "<< folder << " "<<tree<<  endl;
#endif
		_mon->getOnlineMon()->addTreeItemSummary(folder,tree);


        sprintf(tree,"%s/Ch %i - %s",p.getName().c_str(),p.getID(),p.getChannelName().c_str());
        _mon->getOnlineMon()->makeTreeItemSummary(tree); //make summary page
	}
}
