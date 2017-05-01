/*
 * main.c
 *
 *  Created on: 24.04.2017
 *      Author: luke
 */

#include <stdio.h>
#include <util/delay.h>

#include "interrupt_setup.h"
#include "taster.h"
#include "board.h"



ISR(INT0_vect)
{
	toggle_led0();
	//hier taster auslesen

}

int main(void)
{
	setup_board();
	setup_ISR_INT0();

	sei();

	while(1)
	{

	}
}
