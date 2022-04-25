################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/pageModules/baroModule.c \
../Core/Src/pageModules/gpsModule.c \
../Core/Src/pageModules/timeModule.c 

OBJS += \
./Core/Src/pageModules/baroModule.o \
./Core/Src/pageModules/gpsModule.o \
./Core/Src/pageModules/timeModule.o 

C_DEPS += \
./Core/Src/pageModules/baroModule.d \
./Core/Src/pageModules/gpsModule.d \
./Core/Src/pageModules/timeModule.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/pageModules/%.o Core/Src/pageModules/%.su: ../Core/Src/pageModules/%.c Core/Src/pageModules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-pageModules

clean-Core-2f-Src-2f-pageModules:
	-$(RM) ./Core/Src/pageModules/baroModule.d ./Core/Src/pageModules/baroModule.o ./Core/Src/pageModules/baroModule.su ./Core/Src/pageModules/gpsModule.d ./Core/Src/pageModules/gpsModule.o ./Core/Src/pageModules/gpsModule.su ./Core/Src/pageModules/timeModule.d ./Core/Src/pageModules/timeModule.o ./Core/Src/pageModules/timeModule.su

.PHONY: clean-Core-2f-Src-2f-pageModules

