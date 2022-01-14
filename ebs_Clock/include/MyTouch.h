/*
 * MyTouch.h
 *
 * Created: 23/12/2021 09:35:25
 *  Author: Adrian Schnyder
 */ 


#ifndef MYTOUCH_H_
#define MYTOUCH_H_

//To use Less Memory Needs 2 bit
struct Touchtime{
    bool longTouch  :1 ;
    bool shortTouch :1 ; 
};
class Touch{
    int touchpin;
    static int touchounter; //TODO static seems unnessesary
    Touchtime type;

    Touch();

    void updateTouch();
    

}Touch;

//extern Touch touch;


#endif /* MYTOUCH_H_ */