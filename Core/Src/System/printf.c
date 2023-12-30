/*
 * printf.c
 *
 *  Created on: Jan 26, 2023
 *      Author: ayden
 */

#include "printf.h"
#include "UART.h"
#include <stdarg.h>
#include <stdio.h>

#define BUFFER_MAX (80)
static uint8_t buffer[BUFFER_MAX];

int printf (const char* format, ...){

	va_list aptr;
	int ret;

	va_start(aptr, format);
	ret = vsprintf((char *)buffer,format, aptr);
	va_end(aptr);

	USART_Write (USART2, buffer, ret);
	return ret;
}

int puts (const char* string){
	int ret = sprintf((char*)buffer, "%s\n", string);
	USART_Write (USART2, buffer, ret);
	return ret;
}

int putchar(int byte){
	USART_Write (USART2, (uint8_t*)&byte, 1);
	return byte;

}
