/*
 * project.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_PROJECT_H_
#define INC_PROJECT_H_

#include "UART.h"

void run ();
/*void local_echo();*/
void timer_demo();
void flash_demo();
void increment_time();
void runsong();
uint16_t convert_to_uint16 (uint8_t* p_value);
uint32_t convert_to_uint24 (uint8_t* p_value);
uint32_t convert_to_uint32 (uint8_t* p_value);
void play_sound();


#endif /* INC_PROJECT_H_ */
