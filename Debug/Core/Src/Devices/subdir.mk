################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Devices/GPIO.c \
../Core/Src/Devices/LED.c \
../Core/Src/Devices/UART.c \
../Core/Src/Devices/adc.c \
../Core/Src/Devices/dac.c 

OBJS += \
./Core/Src/Devices/GPIO.o \
./Core/Src/Devices/LED.o \
./Core/Src/Devices/UART.o \
./Core/Src/Devices/adc.o \
./Core/Src/Devices/dac.o 

C_DEPS += \
./Core/Src/Devices/GPIO.d \
./Core/Src/Devices/LED.d \
./Core/Src/Devices/UART.d \
./Core/Src/Devices/adc.d \
./Core/Src/Devices/dac.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Devices/%.o Core/Src/Devices/%.su: ../Core/Src/Devices/%.c Core/Src/Devices/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/Demos -I../Core/Inc/Devices -I../Core/Inc/Midi -I../Core/Inc/System -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Devices

clean-Core-2f-Src-2f-Devices:
	-$(RM) ./Core/Src/Devices/GPIO.d ./Core/Src/Devices/GPIO.o ./Core/Src/Devices/GPIO.su ./Core/Src/Devices/LED.d ./Core/Src/Devices/LED.o ./Core/Src/Devices/LED.su ./Core/Src/Devices/UART.d ./Core/Src/Devices/UART.o ./Core/Src/Devices/UART.su ./Core/Src/Devices/adc.d ./Core/Src/Devices/adc.o ./Core/Src/Devices/adc.su ./Core/Src/Devices/dac.d ./Core/Src/Devices/dac.o ./Core/Src/Devices/dac.su

.PHONY: clean-Core-2f-Src-2f-Devices

