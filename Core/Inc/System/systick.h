/*
 * systick.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_
#include "UART.h"

//Struct for the systick timer
typedef struct {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
	uint32_t CTRL;

}SYST;

//this function accesses the counter
uint32_t* get_count();

//this function increments the counter by one, when counter == 10, 1 second has passed.
void update_counter();

// This function is to Initialize SysTick registers
void init_systick();

// This function is to create delay using SysTick timer counter
void delay_systick();

SYST* syst_access();

void SysTick_Handler();

uint32_t* get_elapsed();

void reset();


#endif /* INC_SYSTICK_H_ */
