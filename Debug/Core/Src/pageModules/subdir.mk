################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/pageModules/alarmModule.c \
../Core/Src/pageModules/altitudeModule.c \
../Core/Src/pageModules/baroModule.c \
../Core/Src/pageModules/gpsModule.c \
../Core/Src/pageModules/localInfo.c \
../Core/Src/pageModules/menuModule.c \
../Core/Src/pageModules/screenTest.c \
../Core/Src/pageModules/sdcardModule.c \
../Core/Src/pageModules/settingsModule.c \
../Core/Src/pageModules/stopwatchModule.c \
../Core/Src/pageModules/timerModule.c \
../Core/Src/pageModules/watchfaceModule.c \
../Core/Src/pageModules/worldtimeModule.c 

OBJS += \
./Core/Src/pageModules/alarmModule.o \
./Core/Src/pageModules/altitudeModule.o \
./Core/Src/pageModules/baroModule.o \
./Core/Src/pageModules/gpsModule.o \
./Core/Src/pageModules/localInfo.o \
./Core/Src/pageModules/menuModule.o \
./Core/Src/pageModules/screenTest.o \
./Core/Src/pageModules/sdcardModule.o \
./Core/Src/pageModules/settingsModule.o \
./Core/Src/pageModules/stopwatchModule.o \
./Core/Src/pageModules/timerModule.o \
./Core/Src/pageModules/watchfaceModule.o \
./Core/Src/pageModules/worldtimeModule.o 

C_DEPS += \
./Core/Src/pageModules/alarmModule.d \
./Core/Src/pageModules/altitudeModule.d \
./Core/Src/pageModules/baroModule.d \
./Core/Src/pageModules/gpsModule.d \
./Core/Src/pageModules/localInfo.d \
./Core/Src/pageModules/menuModule.d \
./Core/Src/pageModules/screenTest.d \
./Core/Src/pageModules/sdcardModule.d \
./Core/Src/pageModules/settingsModule.d \
./Core/Src/pageModules/stopwatchModule.d \
./Core/Src/pageModules/timerModule.d \
./Core/Src/pageModules/watchfaceModule.d \
./Core/Src/pageModules/worldtimeModule.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/pageModules/%.o Core/Src/pageModules/%.su: ../Core/Src/pageModules/%.c Core/Src/pageModules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-pageModules

clean-Core-2f-Src-2f-pageModules:
	-$(RM) ./Core/Src/pageModules/alarmModule.d ./Core/Src/pageModules/alarmModule.o ./Core/Src/pageModules/alarmModule.su ./Core/Src/pageModules/altitudeModule.d ./Core/Src/pageModules/altitudeModule.o ./Core/Src/pageModules/altitudeModule.su ./Core/Src/pageModules/baroModule.d ./Core/Src/pageModules/baroModule.o ./Core/Src/pageModules/baroModule.su ./Core/Src/pageModules/gpsModule.d ./Core/Src/pageModules/gpsModule.o ./Core/Src/pageModules/gpsModule.su ./Core/Src/pageModules/localInfo.d ./Core/Src/pageModules/localInfo.o ./Core/Src/pageModules/localInfo.su ./Core/Src/pageModules/menuModule.d ./Core/Src/pageModules/menuModule.o ./Core/Src/pageModules/menuModule.su ./Core/Src/pageModules/screenTest.d ./Core/Src/pageModules/screenTest.o ./Core/Src/pageModules/screenTest.su ./Core/Src/pageModules/sdcardModule.d ./Core/Src/pageModules/sdcardModule.o ./Core/Src/pageModules/sdcardModule.su ./Core/Src/pageModules/settingsModule.d ./Core/Src/pageModules/settingsModule.o ./Core/Src/pageModules/settingsModule.su ./Core/Src/pageModules/stopwatchModule.d ./Core/Src/pageModules/stopwatchModule.o ./Core/Src/pageModules/stopwatchModule.su ./Core/Src/pageModules/timerModule.d ./Core/Src/pageModules/timerModule.o ./Core/Src/pageModules/timerModule.su ./Core/Src/pageModules/watchfaceModule.d ./Core/Src/pageModules/watchfaceModule.o ./Core/Src/pageModules/watchfaceModule.su ./Core/Src/pageModules/worldtimeModule.d ./Core/Src/pageModules/worldtimeModule.o ./Core/Src/pageModules/worldtimeModule.su

.PHONY: clean-Core-2f-Src-2f-pageModules

