#include<avr/io.h>
#include <avr/interrupt.h>

int main() {
  // Begin setup Timer0 - FAST PWM - Non Inverting
  //*********************************************************
  //
  //fast pwm mode                                       : WGM00 =1,  WGM01=1     ----> TCCR0A
  //clear OC0B on compare match and nor inverting output: COM0B1=1, COM0B0=0     ----> TCCR0A
  //clear OC0A on compare match and non inverting output: COM0A1=1, COM0A0=0     ----> TCCR0A
  //Clock PreScale: div 64                              : CS02=0, CS01=1, CS00=1 ----> TCCR0B
  
  DDRD |= _BV(PD5); //Output Mode Timer0 Pins : D5, D6
  PORTD = 0x00; 

  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(WGM02)  | _BV(CS01)  | _BV(CS00); //clear TCNT0 with OCR0A.

  OCR0A = 62;
  OCR0B = 45;//31;
  //******************* End setup Timer0 *********************

  while(1) {  } 

  return 1;
}
