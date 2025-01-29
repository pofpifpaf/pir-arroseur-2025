################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ecran/Ecran_Accueil.c \
../src/Ecran/Ecran_Lancer_Capteur.c \
../src/Ecran/Ecran_Lancer_Prog.c \
../src/Ecran/Ecran_Marche.c \
../src/Ecran/Ecran_Regle_Heure.c \
../src/Ecran/Ecran_Regle_Prog.c 

OBJS += \
./src/Ecran/Ecran_Accueil.o \
./src/Ecran/Ecran_Lancer_Capteur.o \
./src/Ecran/Ecran_Lancer_Prog.o \
./src/Ecran/Ecran_Marche.o \
./src/Ecran/Ecran_Regle_Heure.o \
./src/Ecran/Ecran_Regle_Prog.o 

C_DEPS += \
./src/Ecran/Ecran_Accueil.d \
./src/Ecran/Ecran_Lancer_Capteur.d \
./src/Ecran/Ecran_Lancer_Prog.d \
./src/Ecran/Ecran_Marche.d \
./src/Ecran/Ecran_Regle_Heure.d \
./src/Ecran/Ecran_Regle_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ecran/%.o src/Ecran/%.su src/Ecran/%.cyclo: ../src/Ecran/%.c src/Ecran/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -c -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/core" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/HAL_Driver/Inc" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/Utilities/STM32746G-Discovery" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/CMSIS/device" -I"C:/Users/mahout/Documents/Enseignement/Tutorat -PFE/PIR/PIR Prise_commandee_2024/Pompe_2024_avecRTC&Flash/inc" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-Ecran

clean-src-2f-Ecran:
	-$(RM) ./src/Ecran/Ecran_Accueil.cyclo ./src/Ecran/Ecran_Accueil.d ./src/Ecran/Ecran_Accueil.o ./src/Ecran/Ecran_Accueil.su ./src/Ecran/Ecran_Lancer_Capteur.cyclo ./src/Ecran/Ecran_Lancer_Capteur.d ./src/Ecran/Ecran_Lancer_Capteur.o ./src/Ecran/Ecran_Lancer_Capteur.su ./src/Ecran/Ecran_Lancer_Prog.cyclo ./src/Ecran/Ecran_Lancer_Prog.d ./src/Ecran/Ecran_Lancer_Prog.o ./src/Ecran/Ecran_Lancer_Prog.su ./src/Ecran/Ecran_Marche.cyclo ./src/Ecran/Ecran_Marche.d ./src/Ecran/Ecran_Marche.o ./src/Ecran/Ecran_Marche.su ./src/Ecran/Ecran_Regle_Heure.cyclo ./src/Ecran/Ecran_Regle_Heure.d ./src/Ecran/Ecran_Regle_Heure.o ./src/Ecran/Ecran_Regle_Heure.su ./src/Ecran/Ecran_Regle_Prog.cyclo ./src/Ecran/Ecran_Regle_Prog.d ./src/Ecran/Ecran_Regle_Prog.o ./src/Ecran/Ecran_Regle_Prog.su

.PHONY: clean-src-2f-Ecran

