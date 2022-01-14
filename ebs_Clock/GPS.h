/*
 * GPS.h
 *
 * Created: 20.10.2021 16:25:54
 *  Author: Daniel
 */ 


#ifndef GPS_H_
#define GPS_H_
#include "Arduino.h"
#include <time.h>

// This is a basic class for reading data of a GPS module 
// there's a read method available to get a reference to the last received string, unedited.
// the timeGet method is called to read the time in time_t format. The returned value is NULL whenever no valid GPS string is read.
// the encoder knob by one increment.
// this class is designed for use as a singleton, with direct access to hardware registers

#define RX_BUFFERSIZE 100

class myGPS
{
	public:
	myGPS();
	char *read();
	void timeGet(time_t &time);
	private:
	char rxBuffer[2][RX_BUFFERSIZE];
	uint8_t bufferNum;
	uint8_t bufferIndex;
	int update(void);
};




#endif /* GPS_H_ */