// main.c with demo
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "demo.h"
#include "project.h"
#include "song.h"
#include "GPIO.h"
#include "stm32l4xx.h"
#include "stm32l4xx_hal_gpio.h"
#include "adc_demo.h"
#include "midi.h"
#include "dac.h"
#include "adc.h"
#include "systick.h"
	
int main(void){

	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	LED_Init(PROJECT_LED);
	UART2_Init();
	DAC_Init ();
	DAC_Start ();
	init_systick();
	// application run function
	//run () ;
	//timer_demo();
	//flash_demo();
	//unsigned char test[] = {0x3b};
	//uint8_t* result;

	//ask about timing, why is it off, button clicks within timeframe are messed up
	//where is the original usart writing handler, writing doesnt work now its commented.
	//how tf do i measure 1 second? does the handler run the entire time the button is pressed?
	//if so, check that a second is passed and the handler has been runing the entire time, then pause.
	runsong();
	//play_sound();
	//run_adc_dac_demo();
	//midi_track(0);
	//midi_header(0);
	//GPIO_test();
	//get_delay(result, test);
}

