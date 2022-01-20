/*
 * IncFile1.h
 *
 * Created: 23/12/2021 09:23:03
 *  Author: a
 */ 


#ifndef MyGPSData_H_
#define MyGPSData_H_

#include "include\core\WString.h"
class MyGPSData{
	//TODO  create variables to read/write
	public:
	String	getTime()               ; //TODO adjust to Timeformat
	String	getLatLong()            ;
	String	getConnectionQuality()  ;

	};




#endif /* INCFILE1_H_ */