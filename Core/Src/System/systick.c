#include "systick.h"
#include <stdint.h>
#include "UART.h"

//make a pointer to the registers & initialize

static SYST* systick = (SYST*)0xE000E010;

//One second counter
static uint32_t counter = 0;

static int flag = 0;

//global counter
static uint32_t one_second_elapsed = 0;

uint32_t* get_count(){
	return &counter;
}

void update_counter(){
	if (counter == 10){
		counter = 0 ;
		flag = 1;
	}
	else{
		counter++;
	}
}

SYST* syst_access(){
	return systick;
}

void init_systick(){
	// Use the SysTick global structure pointer to do the following in this
	// exact order with separate lines for each step:
	//
	// Disable SysTick by clearing the CTRL (CSR) register.
	systick->CSR = 0;
	// Set the LOAD (RVR) to 8 million to give us a 100 milliseconds timer.
	systick->RVR = 8000000;
	// Set the clock source bit in the CTRL (CSR) to the internal clock.
	systick->CSR |= 1 << 2;

	systick->CSR |= 1 << 1;
	// Set the enable bit in the CTRL (CSR) to start the timer.
	systick->CSR |= 1;
}

void SysTick_Handler(){
	static uint32_t count = 0;
	counter++;
	count++;
	//80000000 / systick->RVR
	if (count <= 10){
		one_second_elapsed = 1;
		count = 0;
	}
}

void reset(){
	counter = 0;
}

uint32_t* get_elapsed(){
	return &one_second_elapsed;
}
