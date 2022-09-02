################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/utils/cbuffer.c \
../Core/Src/utils/ringBuffer.c \
../Core/Src/utils/timeUtils.c 

OBJS += \
./Core/Src/utils/cbuffer.o \
./Core/Src/utils/ringBuffer.o \
./Core/Src/utils/timeUtils.o 

C_DEPS += \
./Core/Src/utils/cbuffer.d \
./Core/Src/utils/ringBuffer.d \
./Core/Src/utils/timeUtils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/utils/%.o Core/Src/utils/%.su: ../Core/Src/utils/%.c Core/Src/utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-utils

clean-Core-2f-Src-2f-utils:
	-$(RM) ./Core/Src/utils/cbuffer.d ./Core/Src/utils/cbuffer.o ./Core/Src/utils/cbuffer.su ./Core/Src/utils/ringBuffer.d ./Core/Src/utils/ringBuffer.o ./Core/Src/utils/ringBuffer.su ./Core/Src/utils/timeUtils.d ./Core/Src/utils/timeUtils.o ./Core/Src/utils/timeUtils.su

.PHONY: clean-Core-2f-Src-2f-utils

