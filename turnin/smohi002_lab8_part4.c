/*	Author: sana
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//unsigned char B;
unsigned short x;
unsigned short MAX = 0x3FF; 
// around the 9s mark of my lab 2 demo vid, all of the lights were turned on

void ADC_init() {
	ADCSRA |= (1 << ADEN) |(1 << ADSC) | (1 << ADATE);
//	ADEN: setting this bit enables analog-to-digital conversion;
//	ADSC: setting this bit starts the first conversion
//	ADATE:setting this bit enables auto-triggering. 
//		Since we are in Free Running Mode, a new conversion will 
//		trigger whenever the previous conversion completes.
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	while (1) {
		x = ADC;
		if (x >= 0x330)	PORTB = 0xFF;
		if (x >= 0x2CA) PORTB = 0x7F;
		if (x >= 0x264) PORTB = 0x3F;
		if (x >= 0x1FE) PORTB = 0x1F;
		if (x >= 0x198) PORTB = 0x0F;
		if (x >= 0x132) PORTB = 0x07;
		if (x >= 0xCC) PORTB = 0x03;
		if (x >= 0x66) PORTB = 0x01;
		if (x > 0x066) 	PORTB = 0x00;
//		PORTB = B;
	}
    return 1;
}
