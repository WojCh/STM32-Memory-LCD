################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/pageModules/guiUtils/valueSelector.c 

OBJS += \
./Core/Src/pageModules/guiUtils/valueSelector.o 

C_DEPS += \
./Core/Src/pageModules/guiUtils/valueSelector.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/pageModules/guiUtils/%.o Core/Src/pageModules/guiUtils/%.su: ../Core/Src/pageModules/guiUtils/%.c Core/Src/pageModules/guiUtils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-pageModules-2f-guiUtils

clean-Core-2f-Src-2f-pageModules-2f-guiUtils:
	-$(RM) ./Core/Src/pageModules/guiUtils/valueSelector.d ./Core/Src/pageModules/guiUtils/valueSelector.o ./Core/Src/pageModules/guiUtils/valueSelector.su

.PHONY: clean-Core-2f-Src-2f-pageModules-2f-guiUtils

