/*
 * gpio.h
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"
#include "stm32l4xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_gpio.h"

#define S1_Pin GPIO_PIN_9
#define S1_GPIO_Port GPIOA


void GPIO_Init(void);
void GPIO_test(void);
void EXTI15_10_IRQHandler();
void EXTI9_5_IRQHandler();
int* get_local();
uint8_t* get_remote();
uint8_t* get_paused();

#endif /* INC_GPIO_H_ */
