/*
 * MyTouch.cpp
 *
 * Created: 29/12/2021 11:38:05
 *  Author: Adrian Schnyder
 */ 
#include <Arduino.h>
#include "MyTouch.h"
void Touch::updateTouch(){
    const int SHORT_TOUCH    = 6    ;
    const int LONG_TOUCH     = 200  ;
    const int MAX_TIME_TOUCH = 1000 ;
	unsigned int touchCounter = 0;

    if(digitalRead(touchpin)){
       if(touchCounter<MAX_TIME_TOUCH){
            touchCounter++;
        }
    }
    else{
        if(touchCounter>0){
            touchCounter--;
        }        
    }
    //instead of if/else since it can only be either one or the other
    if(touchCounter>MAX_TIME_TOUCH){ type.longTouch  = true; return;}
    type.longTouch  = false;
    if(touchCounter>SHORT_TOUCH)   { type.shortTouch = true; return;}
    type.shortTouch = false;
}
