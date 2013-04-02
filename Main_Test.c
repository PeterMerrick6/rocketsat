/*
 * Main_Test.c
 *
 * Created: 4/1/2013 8:51:12 PM
 *  Author: Peter Merrick
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000

int main(void)
{
  DDRA |= 0xff;
  DDRB |= 0xff;
  DDRC |= 0xff;
  DDRD |= 0xff;
  
  while(1)
  {
  	PORTA ^= 0xff;
  	PORTB ^= 0xff;
  	PORTC ^= 0xff;
  	PORTD ^= 0xff;
  	_delay_ms(1000);
  }
}
