/*
 * MyTime.h.h
 *
 * Created: 23/12/2021 09:36:52
 *  Author:  Adrian Schnyder
 */ 
#include "CountryTime.h"//use myGPSData to updateTime

#ifndef MYTIME_H_
#define MYTIME_H_

#include <time.h>

class MyTime(){
	//TODO get currentTime or worldcountrytime
	//correct for daylightsavingtime 
	void setTime(time_t time); //TODO
	void update();//TODO update with new gpsData, use when updating gpsdata
	time_t getLocaltime(); //TODO
	time_t getWorldTime(); //TODO
	
	
}



#endif /* LOCALTIME_H_ */