################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/File_Handling.c \
../Core/Src/bmp180.c \
../Core/Src/btns.c \
../Core/Src/buttons.c \
../Core/Src/countdownTImer.c \
../Core/Src/customTimer.c \
../Core/Src/gpio.c \
../Core/Src/gps.c \
../Core/Src/gps2.c \
../Core/Src/gui.c \
../Core/Src/i2c.c \
../Core/Src/lcd.c \
../Core/Src/main.c \
../Core/Src/rtc.c \
../Core/Src/sdio.c \
../Core/Src/spi.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/stw.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c \
../Core/Src/vibrationMotor.c 

OBJS += \
./Core/Src/File_Handling.o \
./Core/Src/bmp180.o \
./Core/Src/btns.o \
./Core/Src/buttons.o \
./Core/Src/countdownTImer.o \
./Core/Src/customTimer.o \
./Core/Src/gpio.o \
./Core/Src/gps.o \
./Core/Src/gps2.o \
./Core/Src/gui.o \
./Core/Src/i2c.o \
./Core/Src/lcd.o \
./Core/Src/main.o \
./Core/Src/rtc.o \
./Core/Src/sdio.o \
./Core/Src/spi.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/stw.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o \
./Core/Src/vibrationMotor.o 

C_DEPS += \
./Core/Src/File_Handling.d \
./Core/Src/bmp180.d \
./Core/Src/btns.d \
./Core/Src/buttons.d \
./Core/Src/countdownTImer.d \
./Core/Src/customTimer.d \
./Core/Src/gpio.d \
./Core/Src/gps.d \
./Core/Src/gps2.d \
./Core/Src/gui.d \
./Core/Src/i2c.d \
./Core/Src/lcd.d \
./Core/Src/main.d \
./Core/Src/rtc.d \
./Core/Src/sdio.d \
./Core/Src/spi.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/stw.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d \
./Core/Src/vibrationMotor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/File_Handling.d ./Core/Src/File_Handling.o ./Core/Src/File_Handling.su ./Core/Src/bmp180.d ./Core/Src/bmp180.o ./Core/Src/bmp180.su ./Core/Src/btns.d ./Core/Src/btns.o ./Core/Src/btns.su ./Core/Src/buttons.d ./Core/Src/buttons.o ./Core/Src/buttons.su ./Core/Src/countdownTImer.d ./Core/Src/countdownTImer.o ./Core/Src/countdownTImer.su ./Core/Src/customTimer.d ./Core/Src/customTimer.o ./Core/Src/customTimer.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/gps.d ./Core/Src/gps.o ./Core/Src/gps.su ./Core/Src/gps2.d ./Core/Src/gps2.o ./Core/Src/gps2.su ./Core/Src/gui.d ./Core/Src/gui.o ./Core/Src/gui.su ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/sdio.d ./Core/Src/sdio.o ./Core/Src/sdio.su ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/stw.d ./Core/Src/stw.o ./Core/Src/stw.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/vibrationMotor.d ./Core/Src/vibrationMotor.o ./Core/Src/vibrationMotor.su

.PHONY: clean-Core-2f-Src

