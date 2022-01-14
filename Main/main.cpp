/*
 * Main.c
 *
 * Created: 23/12/2021 09:21:03
 * Author : Adrian Schnyder
 */ 
#include <Arduino.h>
#include <avr/io.h>
#include <Wire.h>
#include <time.h>



//libraries from Ivan Seidel https://github.com/ivanseidel/ArduinoThread
#include "ArduinoThread/Thread.h"
#include "ArduinoThread/ThreadController.h"
// ThreadController that will controll all threads
ThreadController controller = ThreadController();
//My Thread (as a pointer)
Thread* myThread = new Thread();

//This Function is Inline -> Code will be wirtten into Place where used in Code (Less clutter in Setup
void niceCallback(){
	Serial.print("COOL! I'm running on: ");
	Serial.println(millis());
}

inline void setupThread(void){
	//TODO Adjust Threads
		// Configure myThread
		myThread->onRun(niceCallback); //use functionName here
		myThread->setInterval(500);
		
		controller.add(&myThread);  //Ads thread to list to be executed
}

#include "UI.h"
#include "GPS.h"
#include "MyTouch.h"

myGPS gps;




void setupMainView(){

}

void setup(){
	setupThread();
    setupUI();

    gps = myGPS(); //uses serial
    Wire.begin();  //i2c
    //HID
    pinMode(TouchButton, INPUT_PULLUP);
    Touch.touchpin = TouchButton;
    pinMode(EncoderA, INPUT_PULLUP);
    pinMode(EncoderB, INPUT_PULLUP);

    //Output
    //Uhrwerk
    pinMode(CoilA1, OUTPUT);
    pinMode(CoilA2, OUTPUT);
    pinMode(CoilB1, OUTPUT);
    pinMode(CoilB2, OUTPUT);

    //Actors
    pinMode(Buzzer, OUTPUT);
    pinMode(Relais, OUTPUT);

}

int main(void)
{
    /* Replace with your application code */
	// TODO Multithreading 
    while (1) 
    {
	controller.run();	//manages threads
		
    }
}

