################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Driver/Src/Legacy/stm32f7xx_hal_can.c 

OBJS += \
./HAL_Driver/Src/Legacy/stm32f7xx_hal_can.o 

C_DEPS += \
./HAL_Driver/Src/Legacy/stm32f7xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Driver/Src/Legacy/%.o HAL_Driver/Src/Legacy/%.su HAL_Driver/Src/Legacy/%.cyclo: ../HAL_Driver/Src/Legacy/%.c HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/core" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/HAL_Driver/Inc" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/Utilities/STM32746G-Discovery" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/device" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL_Driver-2f-Src-2f-Legacy

clean-HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./HAL_Driver/Src/Legacy/stm32f7xx_hal_can.cyclo ./HAL_Driver/Src/Legacy/stm32f7xx_hal_can.d ./HAL_Driver/Src/Legacy/stm32f7xx_hal_can.o ./HAL_Driver/Src/Legacy/stm32f7xx_hal_can.su

.PHONY: clean-HAL_Driver-2f-Src-2f-Legacy

