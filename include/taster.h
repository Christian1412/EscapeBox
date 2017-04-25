/*
 * taster.h
 *
 *  Created on: 25.04.2017
 *      Author: luke
 */

#ifndef INCLUDE_TASTER_H_
#define INCLUDE_TASTER_H_

#include "gpio.h"

void setup_taster();

inline int read_taster_0();
inline int read_taster_1();
inline int read_taster_2();
inline int read_taster_3();
inline int read_taster_4();
inline int read_taster_5();
inline int read_taster_6();
inline int read_taster_7();
inline int read_taster_8();
inline int read_taster_9();
inline int read_taster_10();
inline int read_taster_11();
inline int read_taster_bonus();
inline int read_taster_key_left();
inline int read_taster_key_right();

#endif /* INCLUDE_TASTER_H_ */
