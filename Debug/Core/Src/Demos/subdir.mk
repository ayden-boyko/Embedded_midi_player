################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Demos/adc_dac_demo.c \
../Core/Src/Demos/demo.c 

OBJS += \
./Core/Src/Demos/adc_dac_demo.o \
./Core/Src/Demos/demo.o 

C_DEPS += \
./Core/Src/Demos/adc_dac_demo.d \
./Core/Src/Demos/demo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Demos/%.o Core/Src/Demos/%.su: ../Core/Src/Demos/%.c Core/Src/Demos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/Demos -I../Core/Inc/Devices -I../Core/Inc/Midi -I../Core/Inc/System -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Demos

clean-Core-2f-Src-2f-Demos:
	-$(RM) ./Core/Src/Demos/adc_dac_demo.d ./Core/Src/Demos/adc_dac_demo.o ./Core/Src/Demos/adc_dac_demo.su ./Core/Src/Demos/demo.d ./Core/Src/Demos/demo.o ./Core/Src/Demos/demo.su

.PHONY: clean-Core-2f-Src-2f-Demos

