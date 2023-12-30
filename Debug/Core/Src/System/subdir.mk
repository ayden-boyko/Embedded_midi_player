################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/System/SysClock.c \
../Core/Src/System/little_endian.c \
../Core/Src/System/printf.c \
../Core/Src/System/syscalls.c \
../Core/Src/System/sysmem.c \
../Core/Src/System/system_stm32l4xx.c \
../Core/Src/System/systick.c 

OBJS += \
./Core/Src/System/SysClock.o \
./Core/Src/System/little_endian.o \
./Core/Src/System/printf.o \
./Core/Src/System/syscalls.o \
./Core/Src/System/sysmem.o \
./Core/Src/System/system_stm32l4xx.o \
./Core/Src/System/systick.o 

C_DEPS += \
./Core/Src/System/SysClock.d \
./Core/Src/System/little_endian.d \
./Core/Src/System/printf.d \
./Core/Src/System/syscalls.d \
./Core/Src/System/sysmem.d \
./Core/Src/System/system_stm32l4xx.d \
./Core/Src/System/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/System/%.o Core/Src/System/%.su: ../Core/Src/System/%.c Core/Src/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/Demos -I../Core/Inc/Devices -I../Core/Inc/Midi -I../Core/Inc/System -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-System

clean-Core-2f-Src-2f-System:
	-$(RM) ./Core/Src/System/SysClock.d ./Core/Src/System/SysClock.o ./Core/Src/System/SysClock.su ./Core/Src/System/little_endian.d ./Core/Src/System/little_endian.o ./Core/Src/System/little_endian.su ./Core/Src/System/printf.d ./Core/Src/System/printf.o ./Core/Src/System/printf.su ./Core/Src/System/syscalls.d ./Core/Src/System/syscalls.o ./Core/Src/System/syscalls.su ./Core/Src/System/sysmem.d ./Core/Src/System/sysmem.o ./Core/Src/System/sysmem.su ./Core/Src/System/system_stm32l4xx.d ./Core/Src/System/system_stm32l4xx.o ./Core/Src/System/system_stm32l4xx.su ./Core/Src/System/systick.d ./Core/Src/System/systick.o ./Core/Src/System/systick.su

.PHONY: clean-Core-2f-Src-2f-System

