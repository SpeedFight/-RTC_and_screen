################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/font.c \
../Src/gpio.c \
../Src/i2c.c \
../Src/io_routines.c \
../Src/lcd.c \
../Src/main.c \
../Src/rtc.c \
../Src/spi.c \
../Src/stm32f0xx_hal_msp.c \
../Src/stm32f0xx_it.c \
../Src/system_stm32f0xx.c \
../Src/text.c \
../Src/tim.c 

OBJS += \
./Src/font.o \
./Src/gpio.o \
./Src/i2c.o \
./Src/io_routines.o \
./Src/lcd.o \
./Src/main.o \
./Src/rtc.o \
./Src/spi.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_it.o \
./Src/system_stm32f0xx.o \
./Src/text.o \
./Src/tim.o 

C_DEPS += \
./Src/font.d \
./Src/gpio.d \
./Src/i2c.d \
./Src/io_routines.d \
./Src/lcd.d \
./Src/main.d \
./Src/rtc.d \
./Src/spi.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_it.d \
./Src/system_stm32f0xx.d \
./Src/text.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"D:/Moje/Programowanie/stm32-develop/Blink/Blink/Inc" -I"D:/Moje/Programowanie/stm32-develop/Blink/Blink/Drivers/STM32F0xx_HAL_Driver/Inc" -I"D:/Moje/Programowanie/stm32-develop/Blink/Blink/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"D:/Moje/Programowanie/stm32-develop/Blink/Blink/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/Moje/Programowanie/stm32-develop/Blink/Blink/Drivers/CMSIS/Include" -I"D:/Moje/Programowanie/stm32-develop/Blink/Blink/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


