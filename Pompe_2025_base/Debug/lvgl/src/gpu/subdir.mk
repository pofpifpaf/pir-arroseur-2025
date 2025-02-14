################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/gpu/lv_gpu_nxp_pxp.c \
../lvgl/src/gpu/lv_gpu_nxp_pxp_osa.c \
../lvgl/src/gpu/lv_gpu_nxp_vglite.c \
../lvgl/src/gpu/lv_gpu_stm32_dma2d.c 

OBJS += \
./lvgl/src/gpu/lv_gpu_nxp_pxp.o \
./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o \
./lvgl/src/gpu/lv_gpu_nxp_vglite.o \
./lvgl/src/gpu/lv_gpu_stm32_dma2d.o 

C_DEPS += \
./lvgl/src/gpu/lv_gpu_nxp_pxp.d \
./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d \
./lvgl/src/gpu/lv_gpu_nxp_vglite.d \
./lvgl/src/gpu/lv_gpu_stm32_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/gpu/%.o lvgl/src/gpu/%.su lvgl/src/gpu/%.cyclo: ../lvgl/src/gpu/%.c lvgl/src/gpu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/core" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/HAL_Driver/Inc" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/Utilities/STM32746G-Discovery" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/device" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-gpu

clean-lvgl-2f-src-2f-gpu:
	-$(RM) ./lvgl/src/gpu/lv_gpu_nxp_pxp.cyclo ./lvgl/src/gpu/lv_gpu_nxp_pxp.d ./lvgl/src/gpu/lv_gpu_nxp_pxp.o ./lvgl/src/gpu/lv_gpu_nxp_pxp.su ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.cyclo ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.su ./lvgl/src/gpu/lv_gpu_nxp_vglite.cyclo ./lvgl/src/gpu/lv_gpu_nxp_vglite.d ./lvgl/src/gpu/lv_gpu_nxp_vglite.o ./lvgl/src/gpu/lv_gpu_nxp_vglite.su ./lvgl/src/gpu/lv_gpu_stm32_dma2d.cyclo ./lvgl/src/gpu/lv_gpu_stm32_dma2d.d ./lvgl/src/gpu/lv_gpu_stm32_dma2d.o ./lvgl/src/gpu/lv_gpu_stm32_dma2d.su

.PHONY: clean-lvgl-2f-src-2f-gpu

