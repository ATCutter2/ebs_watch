/*
 * MyLCD.cpp
 *
 * Created: 29/12/2021 15:48:13
 *  Author: Adrian Schnyder
 */ 

#include "MyLCD.h"



inline void MyLCD::setup(void){
	lcd.begin(16, 2);

// 	lcdThread(printViewToLCD); //use functionName here //TODO Write This into Main Loop
// 	lcdThread->setInterval(500);

}

void MyLCD::printTest(void){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("UpperString ");
	lcd.setCursor(0,1);
	lcd.print("LowerString ");
	
}
void MyLCD::setView(View* view){
	currentView = view;	
	
}
void MyLCD::printViewToLCD(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print(currentView->topString);
	lcd.setCursor(0,1);
	lcd.print(currentView->lowerString);
	
}

void MyLCD::blink(){
	lcd.setBacklight(true);
    //delay(5000); //TODO Paralelize
	lcd.setBacklight(false);
}

void MyLCD::centerText(char* text,byte length){
    char txtCentered   [16];
    int offset = rowlength-length;
    if(offset<2){
        //Serial.print("Too long")
        return;
    }
    offset /=2;

    for(int i = offset;i<16;i++){
        txtCentered[i]=text[i-offset];
    }

}

