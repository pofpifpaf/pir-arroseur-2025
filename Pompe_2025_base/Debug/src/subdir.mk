################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Machine_Etat.c \
../src/Prog_Tempo.c \
../src/RTC_Function.c \
../src/Service_GPIO.c \
../src/Service_Timer.c \
../src/Utility_Flash.c \
../src/main.c 

OBJS += \
./src/Machine_Etat.o \
./src/Prog_Tempo.o \
./src/RTC_Function.o \
./src/Service_GPIO.o \
./src/Service_Timer.o \
./src/Utility_Flash.o \
./src/main.o 

C_DEPS += \
./src/Machine_Etat.d \
./src/Prog_Tempo.d \
./src/RTC_Function.d \
./src/Service_GPIO.d \
./src/Service_Timer.d \
./src/Utility_Flash.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/core" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/HAL_Driver/Inc" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/Utilities/STM32746G-Discovery" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/device" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/Machine_Etat.cyclo ./src/Machine_Etat.d ./src/Machine_Etat.o ./src/Machine_Etat.su ./src/Prog_Tempo.cyclo ./src/Prog_Tempo.d ./src/Prog_Tempo.o ./src/Prog_Tempo.su ./src/RTC_Function.cyclo ./src/RTC_Function.d ./src/RTC_Function.o ./src/RTC_Function.su ./src/Service_GPIO.cyclo ./src/Service_GPIO.d ./src/Service_GPIO.o ./src/Service_GPIO.su ./src/Service_Timer.cyclo ./src/Service_Timer.d ./src/Service_Timer.o ./src/Service_Timer.su ./src/Utility_Flash.cyclo ./src/Utility_Flash.d ./src/Utility_Flash.o ./src/Utility_Flash.su ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

