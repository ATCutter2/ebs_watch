/*
 * connections.h
 *
 * Created: 28/12/2021 22:35:38
 *  Author: Adrian Schnyder
 */ 


#ifndef CONNECTIONS_H_
#define CONNECTIONS_H_

//GPS
//Used as Serial This is only Backup
#define GPS_PIN_RX (0) //TODO Proofcheck
#define GPS_PIN_RX (1) //TODO Proofcheck
 
//Display
//Used as Wire This is only Backup
#define I2C_SDA  (A4) // Data
#define I2C_SCL  (A5) // Clock

//HID
#define TouchButton (5)
#define EncoderA    (7)
#define EncoderB    (8)

//Sensors
#define TemperatureSensor (A2)

//Uhrwerk
#define CoilA1  (9)
#define CoilA2  (10)
#define CoilB1  (11)
#define CoilB2  (12)

//Actors
#define Buzzer (2)
#define Relais (3)


#endif /* CONNECTIONS_H_ */