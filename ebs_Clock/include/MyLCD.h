/*
 * IncFile1.h
 *
 * Created: 23/12/2021 09:25:52
 *  Author: Adrian Schnyder
 */ 

#ifndef MyLCD_H_
#define MyLCD_H_

#include <Wire.h>
#include <rgb_lcd.h>
#include <string.h>

//libraries from Ivan Seidel https://github.com/ivanseidel/ArduinoThread
#include "ArduinoThread/Thread.h"
#include "ArduinoThread/ThreadController.h"
//My Thread (as a pointer)
Thread* lcdThread = new Thread();



#include "UI.h"
//rgb_lcd lcd;
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

class MyLCD{
    const int rowlength   = 16;
    const int columnCount = 2;
	View* currentView;


	inline void setup();	
	void printTest(void);	
	void setView(View view);
	//Updates threads
	void printViewToLCD();	
	void blink();

    void centerText(char* text,unsigned byte length);

	};



#endif /* INCFILE1_H_ */