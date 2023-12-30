################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Midi/midi.c \
../Core/Src/Midi/song.c \
../Core/Src/Midi/tone.c 

OBJS += \
./Core/Src/Midi/midi.o \
./Core/Src/Midi/song.o \
./Core/Src/Midi/tone.o 

C_DEPS += \
./Core/Src/Midi/midi.d \
./Core/Src/Midi/song.d \
./Core/Src/Midi/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Midi/%.o Core/Src/Midi/%.su: ../Core/Src/Midi/%.c Core/Src/Midi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/Demos -I../Core/Inc/Devices -I../Core/Inc/Midi -I../Core/Inc/System -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Midi

clean-Core-2f-Src-2f-Midi:
	-$(RM) ./Core/Src/Midi/midi.d ./Core/Src/Midi/midi.o ./Core/Src/Midi/midi.su ./Core/Src/Midi/song.d ./Core/Src/Midi/song.o ./Core/Src/Midi/song.su ./Core/Src/Midi/tone.d ./Core/Src/Midi/tone.o ./Core/Src/Midi/tone.su

.PHONY: clean-Core-2f-Src-2f-Midi

