/*
 * SimpleStandardWaveform.hh
 *
 *  Created on: Jun 9, 2011
 *      Author: stanitz
 */

#ifndef SimpleStandardWaveform_HH_
#define SimpleStandardWaveform_HH_

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

#include <stdio.h>
#include <string.h>

#include <TROOT.h>
#include "include/OnlineMonConfiguration.hh"

//!Simple Standard Waveform Class
/*!

 */
class SimpleStandardWaveform {
protected:
	std::string _name;
	std::string _channelname;
	int _id;
	ULong64_t _timestamp;
	int _tlu_event;
	int _channelnumber;
public:
	SimpleStandardWaveform(const std::string & name, const int id, OnlineMonConfiguration* mymon);
	SimpleStandardWaveform(const std::string & name, const int id);
	virtual ~SimpleStandardWaveform() {};
	std::string getName() const {return _name;}
	std::string getChannelName() const{return _channelname;}
	void setChannelName(std::string channelname){_channelname = channelname;}
	void setChannelNumber(int channelno){_channelnumber = channelno;};
	void addSuffix( const std::string & suf ) { _name = _name + suf; }
	int getID() const {return _id;}
	void addData(float *data);
	void setMonitorConfiguration(OnlineMonConfiguration *mymon)
	{
		mon=mymon;
	}
	void Calculate();
	float getMax() const{return !calculated?-1e9:_max;};
	float getMin()const{return !calculated?-1e9:_min;};
	float getIntegral() const{return !calculated?getIntegral(0,_nsamples):_integral;}
	float getIntegral(float min, float max) const;
	void setNSamples(unsigned int n_samples){_nsamples = n_samples;}
	unsigned int getNSamples() const{return _nsamples;}
	float* getData() const{return _data;}
	int getSign() const {return _sign;}
	void setSign(int sign){ _sign = sign>0?1:-1;}
	void setTimestamp(ULong64_t timestamp){_timestamp = timestamp;};
	void setEvent(int event){_tlu_event = event;}
	int getEvent() const{return _tlu_event;}
private:
	int _sign;
	bool calculated;
	float *_data;
	float _max;
	float _min;
	float _integral;
	unsigned int _nsamples;
	OnlineMonConfiguration* mon;
};

#endif //ifndef SimpleStandardWaveform_HH_
