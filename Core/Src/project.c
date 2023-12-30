/*
 * project.c
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#include "project.h"
#include "printf.h"
#include "UART.h"
#include "led.h"
#include "systick.h"
#include "song.h"
#include <string.h>
#include "GPIO.h"
#include "tone.h"
#include "dac.h"
#include "midi.h"

#define eol ('\r')

uint8_t bs = '\n';

// Forward declaration
void increment_time();

// This function is to create a delay by consuming CPU cycle on counter
//static void delay_loop( int value )
//{
	// spin loop consuming CPU to spend time.
//	for (int i = 0; i < value; i++)
//		;
//}

//write a function that echos one character
void local_echo(uint8_t byte){
	if (byte == '\r'){
		USART_Write(USART2, &byte, 1);
		USART_Write(USART2, &bs, 1);

	}
	else{
		USART_Write(USART2, &byte, 1);
	}
}

void increment_time(){
	//increment global counter once a second
	uint32_t* counter = (uint32_t*) get_count();
	SYST* systick = syst_access();
	for (int i = 0; i < 10; i++){
		while (!(systick->CSR & (1 << 16)));
	}
	(*counter)++;
}

//project part 2
void runsong(){
	printf("***REMOTE LED CONTROL MENU***\n\r"
			"Available User Commands\n\r"
			"NEXT - Show Next Song info\n\r"
			"PLAY - Play the song (LED On)\n\r"
			"PAUSE - Pause the song (LED Flash)\n\r"
			"STOP - Stop the song (LED off)\n\r"
			"HELP - Displays possible commands\n\r"
			"***REMOTE MODE ACTIVE***");
	LED_Init(PROJECT_LED);
	init_systick();
	GPIO_Init();
	int index = 0;
	char command[16];
	uint8_t* flash = get_paused();
	int count = 0;
	int track = 0;
	//int* flag = get_Flag();
	//int* local = get_local();
	uint8_t* remote = get_remote();
	uint32_t* one_second_elapsed = get_elapsed();
	while(1){
		uint8_t byte = USART_Read_NB(USART2);
		local_echo(byte);
		one_second_elapsed = get_elapsed();
		if ((*flash == 1) && (*one_second_elapsed == 1)){
			increment_time();
			LED_Toggle(PROJECT_LED);
			one_second_elapsed = 0;
		}
		if (*remote == 1){
			if (byte == 0){
				local_echo(byte);
			}
			if (byte == eol){
				command [index] = 0;
				if(strcmp(command, "HELP") == 0){
					printf("***REMOTE LED CONTROL MENU***\n\r"
							"Available User Commands\n\r"
							"NEXT - Show Next Song info\n\r"
							"PLAY - Play the song (LED On)\n\r"
							"PAUSE - Pause the song (LED Flash)\n\r"
							"STOP - Stop the song (LED off)\n\r"
							"HELP - Displays possible commands\n\r");
					*flash = 0;
				}
				else if(strcmp(command, "NEXT") == 0){
					if (track > 4){
						track = 0;
				}
					midi_track(track);
					++track;
					*flash = 0;
				}
				else if(strcmp(command, "PLAY") == 0){
					printf("Playing song: %i\n\r", track);
					LED_On(PROJECT_LED);
					*flash = 0;
					play_song(track);
				}
				else if(strcmp(command, "STOP") == 0){
					printf("Song Stopped\n\r");
					LED_Off(PROJECT_LED);
					*flash = 0;
				}
				else if(strcmp(command, "PAUSE") == 0){
					printf("Song Paused\n\r");
					*flash = 1;
					if (flash){
						LED_Toggle(PROJECT_LED);
					}
				}
				else{
					printf("Invalid Command!\n\r");
				}
				index = 0;
			}
			else if (byte != 0){
				command[index] = byte;
				index++;
			}
			count++;
		}
	}
}

void play_sound () {
    init_systick ();
    DAC_Init ();
    DAC_Start ();
    int duration = hertz_to_duration (155.56);
    uint32_t* count = get_count ();
    int half = duration / 2;
    while (1) {
        if ((*count % duration) < half) {
            DAC_Set_Value (2048);
        }
        else {
            DAC_Set_Value (0);
        }
    }
}


