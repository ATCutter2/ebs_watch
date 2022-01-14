/*
 * MyTime.h.h
 *
 * Created: 23/12/2021 09:36:52
 *  Author:  Adrian Schnyder
 */ 
#include "CountryTime.h"//use myGPSData to updateTime

#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>
#include <chrono>
#include <time.h>


class MyTime(){
	//TODO get currentTime or worldcountrytime
	//correct for daylightsavingtime 
	void setTime(time_t time); //TODO
	void update();//TODO update with new gpsData, use when updating gpsdata
	time_t getLocaltime(); //TODOs
	time_t getWorldTime(); //TODO
	
	auto start = std::chrono::system_clock::now();
	// Some computation here
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
	<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	
}



#endif /* LOCALTIME_H_ */