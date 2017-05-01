/*
 * led.c
 *
 *  Created on: 01.05.2017
 *      Author: luke
 */


#include "led.h"

void setup_led0()
{
	DDRB |=  (1 << PB7);
	PORTB &= ~(1 << PB7);
}

void toggle_led0()
{
	PORTB ^= ( 1 << PB7 );
}
