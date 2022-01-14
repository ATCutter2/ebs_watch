/*
 * UI.h
 *
 * Created: 29/12/2021 00:29:54
 *  Author: Adrian Schnyder
 */ 


#ifndef UI_H_
#define UI_H_

#include "string.h"
class View{
	public:
	char topString   [16];  //I2C Display
	char lowerString [16];  //I2C Display
    View* Top            ;  //The View when Touch long
	View* Deeper         ;  //The View when Touch short
	View* next           ;  //The View when Encoder clockwise
	View* previous       ;  //The View when Encoder counterclockwise
	
	View(
		View* TopScreen     ,
		View* DeeperScreen  ,
		View* nextScreen    ,
		View* previousScreen
	);

	};

volatile View* view; //To be given to LCD and changed by Encoder or Touch
	
View MainView;
	View MainViewSettings,TimeSettingsTimeZone,TimeSettingsTime,TimeSettingsTimeformat;
	View MainViewSettingsSetUhrwerk,ClockSettings;

View WeckerView,WeckerViewSettings;
View WeltStadtView,WeltStadtViewSettings;



#endif /* UI_H_ */