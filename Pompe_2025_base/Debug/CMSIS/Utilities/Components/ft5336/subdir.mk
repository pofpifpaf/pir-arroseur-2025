################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/Utilities/Components/ft5336/ft5336.c 

OBJS += \
./CMSIS/Utilities/Components/ft5336/ft5336.o 

C_DEPS += \
./CMSIS/Utilities/Components/ft5336/ft5336.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/Utilities/Components/ft5336/%.o CMSIS/Utilities/Components/ft5336/%.su CMSIS/Utilities/Components/ft5336/%.cyclo: ../CMSIS/Utilities/Components/ft5336/%.c CMSIS/Utilities/Components/ft5336/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/core" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/HAL_Driver/Inc" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/Utilities/STM32746G-Discovery" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/device" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CMSIS-2f-Utilities-2f-Components-2f-ft5336

clean-CMSIS-2f-Utilities-2f-Components-2f-ft5336:
	-$(RM) ./CMSIS/Utilities/Components/ft5336/ft5336.cyclo ./CMSIS/Utilities/Components/ft5336/ft5336.d ./CMSIS/Utilities/Components/ft5336/ft5336.o ./CMSIS/Utilities/Components/ft5336/ft5336.su

.PHONY: clean-CMSIS-2f-Utilities-2f-Components-2f-ft5336

