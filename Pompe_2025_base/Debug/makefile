################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/System/subdir.mk
-include src/Ecran/subdir.mk
-include src/subdir.mk
-include lvgl/src/widgets/subdir.mk
-include lvgl/src/misc/subdir.mk
-include lvgl/src/hal/subdir.mk
-include lvgl/src/gpu/subdir.mk
-include lvgl/src/font/subdir.mk
-include lvgl/src/extra/widgets/win/subdir.mk
-include lvgl/src/extra/widgets/tileview/subdir.mk
-include lvgl/src/extra/widgets/tabview/subdir.mk
-include lvgl/src/extra/widgets/spinner/subdir.mk
-include lvgl/src/extra/widgets/spinbox/subdir.mk
-include lvgl/src/extra/widgets/span/subdir.mk
-include lvgl/src/extra/widgets/msgbox/subdir.mk
-include lvgl/src/extra/widgets/meter/subdir.mk
-include lvgl/src/extra/widgets/list/subdir.mk
-include lvgl/src/extra/widgets/led/subdir.mk
-include lvgl/src/extra/widgets/keyboard/subdir.mk
-include lvgl/src/extra/widgets/imgbtn/subdir.mk
-include lvgl/src/extra/widgets/colorwheel/subdir.mk
-include lvgl/src/extra/widgets/chart/subdir.mk
-include lvgl/src/extra/widgets/calendar/subdir.mk
-include lvgl/src/extra/widgets/animimg/subdir.mk
-include lvgl/src/extra/themes/mono/subdir.mk
-include lvgl/src/extra/themes/default/subdir.mk
-include lvgl/src/extra/themes/basic/subdir.mk
-include lvgl/src/extra/layouts/grid/subdir.mk
-include lvgl/src/extra/layouts/flex/subdir.mk
-include lvgl/src/extra/subdir.mk
-include lvgl/src/draw/subdir.mk
-include lvgl/src/core/subdir.mk
-include hal_stm_lvgl/touchpad/subdir.mk
-include hal_stm_lvgl/tft/subdir.mk
-include HAL_Driver/Src/Legacy/subdir.mk
-include HAL_Driver/Src/subdir.mk
-include CMSIS/Utilities/STM32746G-Discovery/subdir.mk
-include CMSIS/Utilities/Components/wm8994/subdir.mk
-include CMSIS/Utilities/Components/ov9655/subdir.mk
-include CMSIS/Utilities/Components/ft5336/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Pompe_2024_avecRTC
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Pompe_2024_avecRTC.elf \

MAP_FILES += \
Pompe_2024_avecRTC.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Pompe_2024_avecRTC.list \

OBJCOPY_BIN += \
Pompe_2024_avecRTC.bin \


# All Target
all: main-build

# Main-build Target
main-build: Pompe_2024_avecRTC.elf secondary-outputs

# Tool invocations
Pompe_2024_avecRTC.elf Pompe_2024_avecRTC.map: $(OBJS) $(USER_OBJS) C:\Users\adamg\OneDrive\Documents\1travail\INSA\4A\S8\pir\pir-arroseur-2025\Pompe_2025_base\LinkerScript.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Pompe_2024_avecRTC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\adamg\OneDrive\Documents\1travail\INSA\4A\S8\pir\pir-arroseur-2025\Pompe_2025_base\LinkerScript.ld" --specs=nosys.specs -Wl,-Map="Pompe_2024_avecRTC.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Pompe_2024_avecRTC.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Pompe_2024_avecRTC.list"
	@echo 'Finished building: $@'
	@echo ' '

Pompe_2024_avecRTC.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Pompe_2024_avecRTC.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Pompe_2024_avecRTC.bin Pompe_2024_avecRTC.elf Pompe_2024_avecRTC.list Pompe_2024_avecRTC.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
