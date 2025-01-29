################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/widgets/led/lv_led.c 

OBJS += \
./lvgl/src/extra/widgets/led/lv_led.o 

C_DEPS += \
./lvgl/src/extra/widgets/led/lv_led.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/widgets/led/%.o lvgl/src/extra/widgets/led/%.su lvgl/src/extra/widgets/led/%.cyclo: ../lvgl/src/extra/widgets/led/%.c lvgl/src/extra/widgets/led/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/core" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/HAL_Driver/Inc" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/Utilities/STM32746G-Discovery" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/device" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-led

clean-lvgl-2f-src-2f-extra-2f-widgets-2f-led:
	-$(RM) ./lvgl/src/extra/widgets/led/lv_led.cyclo ./lvgl/src/extra/widgets/led/lv_led.d ./lvgl/src/extra/widgets/led/lv_led.o ./lvgl/src/extra/widgets/led/lv_led.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-led

