/*
 * MyTemperature.h
 *
 * Created: 23/12/2021 09:34:44
 *  Author: Adrian Schnyder
 */ 


#ifndef MYTEMPERATURE_H_
#define MYTEMPERATURE_H_
#include <Arduino.h>
// TODO interface with Temperature / create Class to access Temperature
struct CalibrationPair{
    float isTemperature;
    float measuredValue;
};

class MyTemperature{
    private:
    float temperature;
    float calibrationFactor;
    int zeroOffset;
    volatile int measurment; //may be updated in ISR
    
    void convertInputToTemperature(int measurment);
    public:
    String pin;

    void setupTemperatureSensor(String pinID);

    //m1 is assumed to be Temperature > 0°C
    //ZeroTemp is at 0°C (put in Glass with ice whater)
    void calibrate(CalibrationPair m; CalibrationPair ZeroTemp);

    //to be called when time permits
    void measure(void);

    //Return Value in °C
    float get(void);

};


#endif /* MYTEMPERATURE_H_ */