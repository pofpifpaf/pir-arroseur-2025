################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/lv_draw_arc.c \
../lvgl/src/draw/lv_draw_blend.c \
../lvgl/src/draw/lv_draw_img.c \
../lvgl/src/draw/lv_draw_label.c \
../lvgl/src/draw/lv_draw_line.c \
../lvgl/src/draw/lv_draw_mask.c \
../lvgl/src/draw/lv_draw_rect.c \
../lvgl/src/draw/lv_draw_triangle.c \
../lvgl/src/draw/lv_img_buf.c \
../lvgl/src/draw/lv_img_cache.c \
../lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./lvgl/src/draw/lv_draw_arc.o \
./lvgl/src/draw/lv_draw_blend.o \
./lvgl/src/draw/lv_draw_img.o \
./lvgl/src/draw/lv_draw_label.o \
./lvgl/src/draw/lv_draw_line.o \
./lvgl/src/draw/lv_draw_mask.o \
./lvgl/src/draw/lv_draw_rect.o \
./lvgl/src/draw/lv_draw_triangle.o \
./lvgl/src/draw/lv_img_buf.o \
./lvgl/src/draw/lv_img_cache.o \
./lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./lvgl/src/draw/lv_draw_arc.d \
./lvgl/src/draw/lv_draw_blend.d \
./lvgl/src/draw/lv_draw_img.d \
./lvgl/src/draw/lv_draw_label.d \
./lvgl/src/draw/lv_draw_line.d \
./lvgl/src/draw/lv_draw_mask.d \
./lvgl/src/draw/lv_draw_rect.d \
./lvgl/src/draw/lv_draw_triangle.d \
./lvgl/src/draw/lv_img_buf.d \
./lvgl/src/draw/lv_img_cache.d \
./lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/%.o lvgl/src/draw/%.su lvgl/src/draw/%.cyclo: ../lvgl/src/draw/%.c lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/core" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/HAL_Driver/Inc" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/Utilities/STM32746G-Discovery" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/CMSIS/device" -I"C:/Users/adamg/OneDrive/Documents/1travail/INSA/4A/S8/pir/pir-arroseur-2025/Pompe_2025_base/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw

clean-lvgl-2f-src-2f-draw:
	-$(RM) ./lvgl/src/draw/lv_draw_arc.cyclo ./lvgl/src/draw/lv_draw_arc.d ./lvgl/src/draw/lv_draw_arc.o ./lvgl/src/draw/lv_draw_arc.su ./lvgl/src/draw/lv_draw_blend.cyclo ./lvgl/src/draw/lv_draw_blend.d ./lvgl/src/draw/lv_draw_blend.o ./lvgl/src/draw/lv_draw_blend.su ./lvgl/src/draw/lv_draw_img.cyclo ./lvgl/src/draw/lv_draw_img.d ./lvgl/src/draw/lv_draw_img.o ./lvgl/src/draw/lv_draw_img.su ./lvgl/src/draw/lv_draw_label.cyclo ./lvgl/src/draw/lv_draw_label.d ./lvgl/src/draw/lv_draw_label.o ./lvgl/src/draw/lv_draw_label.su ./lvgl/src/draw/lv_draw_line.cyclo ./lvgl/src/draw/lv_draw_line.d ./lvgl/src/draw/lv_draw_line.o ./lvgl/src/draw/lv_draw_line.su ./lvgl/src/draw/lv_draw_mask.cyclo ./lvgl/src/draw/lv_draw_mask.d ./lvgl/src/draw/lv_draw_mask.o ./lvgl/src/draw/lv_draw_mask.su ./lvgl/src/draw/lv_draw_rect.cyclo ./lvgl/src/draw/lv_draw_rect.d ./lvgl/src/draw/lv_draw_rect.o ./lvgl/src/draw/lv_draw_rect.su ./lvgl/src/draw/lv_draw_triangle.cyclo ./lvgl/src/draw/lv_draw_triangle.d ./lvgl/src/draw/lv_draw_triangle.o ./lvgl/src/draw/lv_draw_triangle.su ./lvgl/src/draw/lv_img_buf.cyclo ./lvgl/src/draw/lv_img_buf.d ./lvgl/src/draw/lv_img_buf.o ./lvgl/src/draw/lv_img_buf.su ./lvgl/src/draw/lv_img_cache.cyclo ./lvgl/src/draw/lv_img_cache.d ./lvgl/src/draw/lv_img_cache.o ./lvgl/src/draw/lv_img_cache.su ./lvgl/src/draw/lv_img_decoder.cyclo ./lvgl/src/draw/lv_img_decoder.d ./lvgl/src/draw/lv_img_decoder.o ./lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-lvgl-2f-src-2f-draw

