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


//////////////////////////////////////////////////////////////////////////
// implementing "Multitasking" 
//libraries from Ivan Seidel https://github.com/ivanseidel/ArduinoThread
#include "ArduinoThread/Thread.h"
#include "ArduinoThread/ThreadController.h"
// ThreadController that will control all threads
ThreadController controller = ThreadController();
//////////////////////////////////////////////////////////////////////////
#include "UI.h"
#include "GPS.h"
#include "MyTouch.h"

myGPS gps;


//////////////////////////////////////////////////////////////////////////
//Example Implementing a Thread
//This Function is Inline -> Code will be wirtten into Place where used in Code (Less clutter in Setup)
//My Thread (as a pointer)
Thread* myThread = new Thread();
void niceCallback(){
	Serial.print("COOL! I'm running on: ");
	Serial.println(millis());
}

inline void setupThread(void){
	//TODO Adjust Threads
		// Configure myThread
		myThread->onRun(niceCallback); //use functionName here
		myThread->setInterval(500);  
		controller.add(&myThread);  //Adds thread to list to be executed
}
//////////////////////////////////////////////////////////////////////////


Thread* viewThread = new Thread();
/*Thread for Views
* executes attached function
*/
inline void viewThread(void){				  //This Function is Inline -> Code will be wirtten into Place where used in Code (Less clutter in Setup)
	viewThread->onRun(view->executeFunction); //TODO Verify, that a change of functions changes what is done
	viewThread->setInterval(500);
	controller.add(&viewThread);			  //TODO may need to be deleted and redone with view change
}


void setup(){
	setupThread();
    setupViews();
	viewThread();
	MainView.executeFunction  = mainViewWorkings; //example of giving a specific View a function
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
	setup();
    /* Replace with your application code */
	// TODO Multi threading 
    while (1) 
    {
	controller.run();	//manages threads
		
    }
}

