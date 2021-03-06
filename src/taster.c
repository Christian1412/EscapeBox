/*
 * taster.c
 *
 *  Created on: 25.04.2017
 *      Author: luke
 */


#include "taster.h"

//setup Pin 22, inout, pull-up-resistor
static void setup_taster_0()
{
	DDRA &= ~(1 << PA0);
	PORTA |= (1 << PA0);
}

//setup Pin 23, inout, pull-up-resistor
static void setup_taster_1()
{
	DDRA &= ~(1 << PA1);
	PORTA |= (1 << PA1);
}

//setup Pin 24, inout, pull-up-resistor
static void setup_taster_2()
{
	DDRA &= ~(1 << PA2);
	PORTA |= (1 << PA2);
}

//setup Pin 25, inout, pull-up-resistor
static void setup_taster_3()
{
	DDRA &= ~(1 << PA3);
	PORTA |= (1 << PA3);
}

//setup Pin 26, inout, pull-up-resistor
static void setup_taster_4()
{
	DDRA &= ~(1 << PA4);
	PORTA |= (1 << PA4);
}

//setup Pin 27, inout, pull-up-resistor
static void setup_taster_5()
{
	DDRA &= ~(1 << PA5);
	PORTA |= (1 << PA5);
}

//setup Pin 28, inout, pull-up-resistor
static void setup_taster_6()
{
	DDRA &= ~(1 << PA6);
	PORTA |= (1 << PA6);
}

//setup Pin 29, inout, pull-up-resistor
static void setup_taster_7()
{
	DDRA &= ~(1 << PA7);
	PORTA |= (1 << PA7);
}

//setup Pin 30, inout, pull-up-resistor
static void setup_taster_8()
{
	DDRC &= ~(1 << PC7);
	PORTC |= (1 << PC7);
}

//setup Pin 31, inout, pull-up-resistor
static void setup_taster_9()
{
	DDRC &= ~(1 << PC6);
	PORTC |= (1 << PC6);
}

//setup Pin 32, inout, pull-up-resistor
static void setup_taster_10()
{
	DDRC &= ~(1 << PC5);
	PORTC |= (1 << PC5);
}

//setup Pin 33, inout, pull-up-resistor
static void setup_taster_11()
{
	DDRC &= ~(1 << PC4);
	PORTC |= (1 << PC4);
}

//setup Pin 21, inout, pull-up-resistor
static void setup_taster_bonus()
{
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);
}

//setup Pin 43, inout, pull-up-resistor
static void setup_taster_key_left()
{
	DDRL &= ~(1 << PL6);
	PORTL |= (1 << PL6);
}

//setup Pin 44, inout, pull-up-resistor
static void setup_taster_key_right()
{
	DDRL &= ~(1 << PL5);
	PORTL |= (1 << PL5);
}



//summarize all setup-function to one function-call
void setup_taster()
{
	setup_taster_0();
	setup_taster_1();
	setup_taster_2();
	setup_taster_3();
	setup_taster_4();
	setup_taster_5();
	setup_taster_6();
	setup_taster_7();
	setup_taster_8();
	setup_taster_9();
	setup_taster_10();
	setup_taster_11();
	setup_taster_bonus();
	setup_taster_key_left();
	setup_taster_key_right();
}

inline taster_state_t read_taster_0()
{
	return (taster_state_t)(PINA >> PA0) & 1 ;
}

inline taster_state_t read_taster_1()
{
	return (taster_state_t) (PINA >> PA1) & 1 ;
}

inline taster_state_t read_taster_2()
{
	return (taster_state_t) (PINA >> PA2) & 1 ;
}

inline taster_state_t read_taster_3()
{
	return (taster_state_t) (PINA >> PA3) & 1 ;
}

inline taster_state_t read_taster_4()
{
	return (taster_state_t) (PINA >> PA4) & 1 ;
}

inline taster_state_t read_taster_5()
{
	return (taster_state_t) (PINA >> PA5) & 1 ;
}

inline taster_state_t read_taster_6()
{
	return (taster_state_t) (PINA >> PA6) & 1 ;
}

inline taster_state_t read_taster_7()
{
	return (taster_state_t) (PINA >> PA7) & 1 ;
}

inline taster_state_t read_taster_8()
{
	return (taster_state_t) (PINC >> PC7) & 1 ;
}

inline taster_state_t read_taster_9()
{
	return (taster_state_t) (PINC >> PC6) & 1 ;
}

inline taster_state_t read_taster_10()
{
	return (taster_state_t) (PINC >> PC5) & 1 ;
}

inline taster_state_t read_taster_11()
{
	return (taster_state_t) (PINC >> PC4) & 1 ;
}

inline taster_state_t read_taster_bonus()
{
	return (taster_state_t) (PING >> PG5) & 1 ;
}

inline taster_state_t read_taster_key_left()
{
	return (taster_state_t) (PING >> PL6) & 1 ;
}

inline taster_state_t read_taster_key_right()
{
	return (taster_state_t) (PING >> PL5) & 1 ;
}

