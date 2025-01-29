################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.c \
../CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.o \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.o 

C_DEPS += \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.d \
./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/Utilities/STM32746G-Discovery/%.o CMSIS/Utilities/STM32746G-Discovery/%.su CMSIS/Utilities/STM32746G-Discovery/%.cyclo: ../CMSIS/Utilities/STM32746G-Discovery/%.c CMSIS/Utilities/STM32746G-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/core" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/HAL_Driver/Inc" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/Utilities/STM32746G-Discovery" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/device" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CMSIS-2f-Utilities-2f-STM32746G-2d-Discovery

clean-CMSIS-2f-Utilities-2f-STM32746G-2d-Discovery:
	-$(RM) ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_audio.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_camera.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_eeprom.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_qspi.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sd.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_sdram.su ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.cyclo ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.d ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.o ./CMSIS/Utilities/STM32746G-Discovery/stm32746g_discovery_ts.su

.PHONY: clean-CMSIS-2f-Utilities-2f-STM32746G-2d-Discovery

