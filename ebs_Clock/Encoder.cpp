/*
 Author: Daniel Binggeli
  
*/
#include "Encoder.h"
#include "Arduino.h"
//#include <avr\iom328p.h>
#include <util\atomic.h>
#include "Encoder.h"


static  char ab = 0, old_ab = 0;

// this variable is used to count revolution increments of a rotary encoder
// it is declared volatile because it's accessed from the pin-change ISR, and
// from within the class Encoder. 
static volatile int count = 0;

// this constructor initializes the pins 2 and 3 of PortC for use as pin-change interrupt signals
// the PCx registers are set up for both signals to produce an interrupt on each level change.
Encoder::Encoder()
{
  DDRC &= ~(1<<PINC2)&~(1<<PINC3); // set A, B as inputs
  PORTC |= (1<<PORTC2)|(1<<PORTC3); // ..with pullups
    
  PCICR|=(1<<PCIE1);   //enable PCINT[8:15]
  PCIFR=(1<<PCIF1);    //clear PCINT[8:15] interrupt flag bit
  PCMSK1=(1<<PCINT10);//unmask A == PCINT10 == PINC2/ADC2/A2
  PCMSK1|=(1<<PCINT11);//unmask B == PCINT11 == PINC3/ADC3/A3 
}

// read method of the class Encoder
// ------------------------------------------------------------------------
// the actual count value is returned. 
// because the encoder button counts up by 2 per step, this is corrected here beforehand.
// count as a multi-byte variable has to be protected against interrupt access while read.
// this is achieved with the gcc-macro ATOMIC_BLOCK
int Encoder::read(){
  int c;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
     c = count;
  }
  return (c+1)/2; // avoid counting by two 
  
}

void Encoder::eventGet(char &eventUp, char &eventDown){
  static int old_count = -32768;
  if(old_count == -32768) old_count = count;
  if(count > old_count+1) {
    eventUp = 1;
    eventDown = 0;
    old_count = count;
  } else if(count < old_count-1) {
    eventUp = 0;
    eventDown = 1;
    old_count = count;
  } else {
    eventUp = 0;
    eventDown = 0;
  }

}

// ISR(PCINT1_vect)
// ------------------------------------------------------------------------
// this ISR belongs to the class Encoder, together with the variable count.
// it is called on every change on PCINT10 pin and PCINT11 pin. 
// The appropriate setup is done in the constructor of the class Encoder. 
// it first acquires the signals on PCINT10 and PCINT11, the so-called AB signal.
// then this signal is compared with the old copy from the last ISR call to detect changes.
// if A has changed, the level on B is checked to determine the sense of movement, and
// the counter is incremented or decremented accordingly.
// (Because the signal A bounces, both edges must be detected and counted. 
// With non-bouncing signals, one edge would be sufficient.)
// changes on B do not count, but only a copy of the signal is stored in old_ab.
// the cases 0 and 3 shouldn't occur at all, if the encoder is operated properly.
// Because of the bouncing signals, they could in fact occur, but both are simply ignored.
// It is not recommended to save the signal AB in these error states.

ISR(PCINT1_vect)
{
  ab = 3&(PINC>>PINC2); // acquire AB signal
  
  switch(ab^old_ab){//exor with old copy to detect changes
    case 1: // change on A
      if((ab==3)||(ab==0)) count++; // (+) if B == 1
      else count--; // (-) otherwise
      old_ab = ab; // save a copy of AB signal for next ISR call
    break;
    case 2: // change on B don't count
      old_ab = ab; // just save a copy of AB signal
    break;
    default: // no change, or both changed
    //ignore, do not save
    break;
  }
}

Encoder encoder;
