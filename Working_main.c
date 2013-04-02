/*
 * GccApplication4.c
 *
 * Created: 3/18/2013 4:53:13 PM
 *  Author: Peter Merrick
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define DUTY1 OCR2A
#define DUTY2 OCR2B
#define F_CPU 16000000UL

uint32_t volatile second = 0;

void init_pwm(){
  cli();
  TCCR2B |= (1<<WGM22);
  TCCR2A |= (1<<WGM20) | (1<< COM2A1) | (1<< COM2B1);
  sei();
}

void init_time(){
  cli();
  TCCR1B |= (1<< WGM12) | (1<<CS12);
  TCCR1A |= (1<< COM1A0);
  TCNT1 = 0;
  OCR1A = 62499;
  TIMSK1 |=  (1<< OCIE1A);
  sei();
}
ISR(TIMER1_COMPA_vect){
  second++;
}

int main(void)

{
  DDRD |= (1<<7) | (1<<6);
  init_pwm();
  init_time();
  
    while(1)
    {  	
  	if(second%2 == 0){
  		DUTY1 = 200;	
  		DUTY2 = 200;
  	}		
  	else{
  		DUTY1 = 50;
  		DUTY2 = 50;
  	}	
  	_delay_ms(500);	
    }
}
