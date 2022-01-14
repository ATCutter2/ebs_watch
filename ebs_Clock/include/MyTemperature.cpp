/*
 * MyTemperature.cpp
 *
 * Created: 29/12/2021 18:18:40
 *  Author: Adrian Schnyder
 */ 

#include "MyTemperature.h"
#include <Arduino.h>


void MyTemperature::convertInputToTemperature(){
    //y = m*x+c
    return (calibrationFactor*measurment +zeroOffset);
}

void MyTemperature::setupTemperatureSensor(String pinID){
    pin = pinID;
}
void MyTemperature::calibrate(CalibrationPair m; CalibrationPair ZeroTemp){
    //y = m*x+c
    // c = 
    zeroOffset = -ZeroTemp.measuredValue;
    // we find the m here
    calibrationFactor = (m.isTemperature - ZeroTemp.isTemperature) /( m.measuredValue -ZeroTemp.measuredValue);
}

}
void MyTemperature::measure(void){
    measurment = analogRead(sensorPin);
}

float MyTemperature::get(void){
    return convertInputToTemperature();
}