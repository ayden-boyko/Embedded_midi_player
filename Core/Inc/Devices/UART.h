#ifndef __NUCLEO476_UART_H
#define __NUCLEO476_UART_H

#include "stm32l476xx.h"

#define BUFFER_SIZE (32)

typedef struct {
	unsigned char* command[100];
	unsigned int end_char;
}thingy;

void UART2_Init(void);
void UART2_GPIO_Init(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART_Init(USART_TypeDef * USARTx);
void USART_Write(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t nBytes);
uint8_t   USART_Read(USART_TypeDef * USARTx);
uint8_t USART_Read_NB (USART_TypeDef * USARTx);
void USART_Delay(uint32_t us);
void USART_IRQHandler(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t * pRx_counter);
void USART2_IRQHandler (void);

thingy* get_buffer();

#endif /* __NUCLEO476_UART_H */
