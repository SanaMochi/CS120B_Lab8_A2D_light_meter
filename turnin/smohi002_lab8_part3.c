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

unsigned short x;
unsigned const char MAX = 0x3FF; 
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
		if (x >= (MAX / 2)) {
			PORTB = 0x01;
			PORTD = 0x00;
//			PORTB = (char)x; //lower 8 bits
//			PORTD = (char)(x >> 4); //higher 8 bits
		}
		else { 
			PORTB = 0x00;
			PORTD = 0x00;
		}
	}
    return 1;
}
