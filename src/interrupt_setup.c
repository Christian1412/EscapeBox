/*
 * interrupt.c
 *
 *  Created on: 01.05.2017
 *      Author: luke
 */


#include "interrupt_setup.h"

void setup_ISR_INT0()
{
	EIMSK |= 1<<INT0;
	EICRA |= 1<<ISC01 | 1<<ISC00;
	//MCUCR |= 1<<ISC01 | 1<<ISC00;
}

