/*
 * MyTemperature.cpp
 *
 * Created: 29/12/2021 18:18:40
 *  Author: Adrian Schnyder
 */ 

#include "MyTemperature.h"
#include <Arduino.h>
#include <math.h>



float MyTemperature::convertInputToTemperature(){
	float R = 1023.0/measurment-1.0;
    R = R0*R;
	float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
    return (temperature);
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