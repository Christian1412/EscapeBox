/*
 * taster.h
 *
 *  Created on: 25.04.2017
 *      Author: luke
 */

#ifndef INCLUDE_TASTER_H_
#define INCLUDE_TASTER_H_

#include "gpio.h"

typedef gpio_state_t taster_state_t;
typedef uint16_t taster_states_t;

void setup_taster();

inline taster_state_t read_taster_0();
inline taster_state_t read_taster_1();
inline taster_state_t read_taster_2();
inline taster_state_t read_taster_3();
inline taster_state_t read_taster_4();
inline taster_state_t read_taster_5();
inline taster_state_t read_taster_6();
inline taster_state_t read_taster_7();
inline taster_state_t read_taster_8();
inline taster_state_t read_taster_9();
inline taster_state_t read_taster_10();
inline taster_state_t read_taster_11();
inline taster_state_t read_taster_bonus();
inline taster_state_t read_taster_key_left();
inline taster_state_t read_taster_key_right();

#endif /* INCLUDE_TASTER_H_ */
