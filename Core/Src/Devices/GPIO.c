/*
 * gpio.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */


/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"
#include <stdbool.h>
#include "led.h"
#include "stm32l4xx.h"
#include "stm32l4xx_hal_gpio.h"
#include <stdio.h>
#include "systick.h"
#include "main.h"
#include "song.h"
#include "little_endian.h"
#include "midi.h"

// External Global Variables that we will need access to
int flag = 0;
int switched = 1;
int down = 0;
int check = 0;
int presses = 0;
int play = 1;
int local = 0;
uint32_t* counting = 0;
uint8_t blink = 0;
uint8_t remote = 1;
uint8_t* one_second = 0;
uint8_t player = 0;
uint8_t paused = 0;
int first = 0;
int pressed = 0;
int stopped = 0;

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = S1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(S1_GPIO_Port, &GPIO_InitStruct);

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);

}

void GPIO_test(){
	GPIO_Init();
	LED_Init(PROJECT_LED);
	init_systick();
	uint32_t* one_second_elapsed = get_elapsed();

	while(1){
		if(*one_second_elapsed){
			LED_Toggle(PROJECT_LED);
			*one_second_elapsed = 0;
		}
//		if (HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin)){
//			LED_On(PROJECT_LED);
//		}
//		else{
//			LED_Off(PROJECT_LED);
//		}
	}

	/* EXTI15_10_IRQn interrupt init*/
	// Note you will have to add EXTI15_10_IRQn Interrupt handler function as well
	// This is the interrupt handler for the blue button


	/* EXTI9_5_IRQn interrupt init*/
	// Note you will have to add EXTI9_15_IRQn Interrupt handler function as well
	// This is the interrupt handler for the external buttons (S1)

}

//blue button
void EXTI15_10_IRQHandler(){
	GPIO_PinState state = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	HAL_GPIO_TogglePin(B1_GPIO_Port, B1_Pin);
	while(state != switched){
		state = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	}
	if(state == 1){
		switched = 0;
		remote = 0;
		local = 1;
		printf("\n\r***MANUAL OVERRIDE MODE ACTIVE***\n\r");
	}
	if(state == 0){
		switched = 1;
		remote = 1;
		local = 0;
		LED_Off(PROJECT_LED);
		blink = 0;
		printf("\n\r***REMOTE MODE ACTIVE***\n\r");
	}
	HAL_GPIO_EXTI_IRQHandler(B1_Pin);
}

//s1 button
void EXTI9_5_IRQHandler(){
	if(local == 1){
		GPIO_PinState state = HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin);
		if(state == GPIO_PIN_SET){
			if(presses == 0){
				reset();
				one_second = 0;
			}
			presses++;
			HAL_GPIO_EXTI_IRQHandler(S1_Pin);
		}
		if(state == 0){
			if (presses > 1 && *get_count() <= 2){
				presses = 1;
			}
			if(presses == 1 && *get_count() > 10){
				LED_Off(PROJECT_LED);
				first = 1;
				printf("stopped song\n\r");
				presses = 0;
				one_second = 0;
				paused = 0;
				first = 0;

			}
			if(presses >= 2 && *get_count() < 10){
				first = 0;
				presses = 0;
				one_second = 0;
				if(player == 5){
					player = 0;
				}
				else{
					midi_track(player);
					player++;
				}

			}
			else if((presses == 1) && (first == 0)){
				LED_On(PROJECT_LED);
				first = 1;
				printf("playing song\n\r");
				presses = 0;
				play_song(player);

			}
			else if ((presses == 1) && (first == 1)){
				if (paused == 1){
					paused = 0;
					first = 1;
					printf("song resumed\n\r");
					LED_On(PROJECT_LED);
					presses = 0;

				}
				else{
					paused = 1;
					presses = 0;
					printf("song paused\n\r");

				}
			}
			else{
				presses = 0;
			}
			reset();
			HAL_GPIO_EXTI_IRQHandler(S1_Pin);
		}
	}
	HAL_GPIO_EXTI_IRQHandler(S1_Pin);
}

int* get_local(){
	return &local;
}

uint8_t* get_remote(){
	return &remote;
}

uint8_t* get_paused(){
	return &paused;
}
