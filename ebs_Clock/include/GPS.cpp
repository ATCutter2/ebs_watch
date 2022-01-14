/*
 * GPS.cpp
 *
 * Created: 20.10.2021 16:25:36
 *  Author: Daniel
 */ 
#include "GPS.h"
#include <avr\pgmspace.h>

myGPS::myGPS(){
	Serial.begin(9600);
	bufferNum = 0;
	bufferIndex = 0;
	rxBuffer[0][0] = rxBuffer[1][0] = '\0';
}

char *myGPS::read()
{
	char * rxp = NULL;
	if(update() == 1){ //REad vollst?ndig
		rxp = (bufferNum == 1) ? rxBuffer[0] : rxBuffer[1]; // den jeweils gef?llten nehmen, der andere, auf den bufferNum zeigt, wird gerade beschrieben
	}
	return rxp;
}

void myGPS::timeGet(time_t &tm)//aprs.gids.nl
{
	char *token[8];
	uint8_t nr = 0;
	if(update() == 1){
		char *rxp = (bufferNum == 1) ? rxBuffer[0] : rxBuffer[1]; // den jeweils gef?llten nehmen, der andere, auf den bufferNum zeigt, wird gerade beschrieben
		token[0] = strtok(rxp,",");
		for(nr = 1; nr < 8; nr++){
			if( (token[nr] = strtok(NULL, ",")) == NULL) break; //Dont look at empty
		}
		if(strstr(&token[0][3], "RMC") != 0) {
			Serial.print(token[1]); //time
			Serial.println("TIME");
			tm = 1;
		}
		else tm = 0;
	}
}

int myGPS::update(){
	int ret = 0;
	char c = '\0';
	while(Serial.available()){
		c = Serial.read();
		if((c=='\r')||(c=='\n')) { //newline -> string ende
			rxBuffer[bufferNum][min((RX_BUFFERSIZE-1),bufferIndex)] = '\0';
			
			if(bufferIndex > 0){ //wenn etwas in Buffer
				//Buffer umschalten
				if(bufferNum == 1) bufferNum = 0;
				else bufferNum  = 1;
			}
			bufferIndex = 0; //index auf Anfang
			ret = 1; //Return buffer ok
		}
		else if(bufferIndex < RX_BUFFERSIZE) rxBuffer[bufferNum][bufferIndex++] = c; //schreibe solange Buffer Platz hat
	}
	return ret;
}
