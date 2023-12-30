#include "UART.h"


uint16_t convert_to_uint16 (uint8_t* ptr) {
    uint16_t num = (ptr[0] << 8) + ptr [1];
    return num;
}

uint32_t convert_to_uint32 (uint8_t* ptr) {
    uint32_t num = (ptr[0] << 24) + (ptr [1] << 16) + (ptr[2] << 8) + ptr [3];
    return num;
}

uint32_t convert_to_uint24 (uint8_t* ptr){
	uint32_t num = (ptr[0]<<16) + (ptr[1]<<8) + ptr[2];
	return num;
}
