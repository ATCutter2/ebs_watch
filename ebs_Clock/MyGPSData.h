/*
 * IncFile1.h
 *
 * Created: 23/12/2021 09:23:03
 *  Author: a
 */ 


#ifndef MyGPSData_H_
#define MyGPSData_H_

#include <iomanip>

class MyGPSData{
	//TODO  create variables to read/write
	public:
	char[5]	getTime(); //TODO adjust to Timeformat
	char[]	getLatLong();
	char[]	getConnectionQuality();

	};




#endif /* INCFILE1_H_ */