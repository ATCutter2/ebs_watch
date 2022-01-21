/*
 * IncFile1.h
 *
 * Created: 23/12/2021 09:25:52
 *  Author: Adrian Schnyder
 */ 

#ifndef MyLCD_H_
#define MyLCD_H_

#include "include\libraries\Wire\Wire.h"
#include "include\libraries\grove_-_lcd_rgb_backlight\rgb_lcd.h"
#include "include\core\WString.h"

//libraries from Ivan Seidel https://github.com/ivanseidel/ArduinoThread
#include "ArduinoThread/Thread.h"
#include "ArduinoThread/ThreadController.h"

#include "UI.h"
//rgb_lcd lcd;
//Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
rgb_lcd lcd = rgb_lcd();

class MyLCD{
    const int rowlength   = 16;
    const int columnCount = 2;
	View* currentView;


	inline void setup();	
	void printTest(void);	
	void setView(View* view);
	//Updates threads
	void printViewToLCD();	
	void blink();

    void centerText(char* text,byte length);

	};



#endif /* INCFILE1_H_ */