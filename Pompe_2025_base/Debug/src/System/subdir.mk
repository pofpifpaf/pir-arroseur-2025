################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/System/startup_stm32f746xx.s 

C_SRCS += \
../src/System/stm32f7xx_it.c \
../src/System/syscalls.c \
../src/System/sysmem.c \
../src/System/system_stm32f7xx.c 

OBJS += \
./src/System/startup_stm32f746xx.o \
./src/System/stm32f7xx_it.o \
./src/System/syscalls.o \
./src/System/sysmem.o \
./src/System/system_stm32f7xx.o 

S_DEPS += \
./src/System/startup_stm32f746xx.d 

C_DEPS += \
./src/System/stm32f7xx_it.d \
./src/System/syscalls.d \
./src/System/sysmem.d \
./src/System/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/System/%.o: ../src/System/%.s src/System/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
src/System/%.o src/System/%.su src/System/%.cyclo: ../src/System/%.c src/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/core" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/HAL_Driver/Inc" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/Utilities/STM32746G-Discovery" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/device" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-System

clean-src-2f-System:
	-$(RM) ./src/System/startup_stm32f746xx.d ./src/System/startup_stm32f746xx.o ./src/System/stm32f7xx_it.cyclo ./src/System/stm32f7xx_it.d ./src/System/stm32f7xx_it.o ./src/System/stm32f7xx_it.su ./src/System/syscalls.cyclo ./src/System/syscalls.d ./src/System/syscalls.o ./src/System/syscalls.su ./src/System/sysmem.cyclo ./src/System/sysmem.d ./src/System/sysmem.o ./src/System/sysmem.su ./src/System/system_stm32f7xx.cyclo ./src/System/system_stm32f7xx.d ./src/System/system_stm32f7xx.o ./src/System/system_stm32f7xx.su

.PHONY: clean-src-2f-System

