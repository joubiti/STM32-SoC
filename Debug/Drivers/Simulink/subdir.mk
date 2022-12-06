################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Simulink/STMpil.c \
../Drivers/Simulink/STMpil_data.c \
../Drivers/Simulink/rtGetInf.c \
../Drivers/Simulink/rtGetNaN.c \
../Drivers/Simulink/rt_nonfinite.c 

OBJS += \
./Drivers/Simulink/STMpil.o \
./Drivers/Simulink/STMpil_data.o \
./Drivers/Simulink/rtGetInf.o \
./Drivers/Simulink/rtGetNaN.o \
./Drivers/Simulink/rt_nonfinite.o 

C_DEPS += \
./Drivers/Simulink/STMpil.d \
./Drivers/Simulink/STMpil_data.d \
./Drivers/Simulink/rtGetInf.d \
./Drivers/Simulink/rtGetNaN.d \
./Drivers/Simulink/rt_nonfinite.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Simulink/%.o Drivers/Simulink/%.su: ../Drivers/Simulink/%.c Drivers/Simulink/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Asus/Desktop/documents et projets pour stage/ALSTOM/STM/PIL Delay/Drivers/Simulink" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Simulink

clean-Drivers-2f-Simulink:
	-$(RM) ./Drivers/Simulink/STMpil.d ./Drivers/Simulink/STMpil.o ./Drivers/Simulink/STMpil.su ./Drivers/Simulink/STMpil_data.d ./Drivers/Simulink/STMpil_data.o ./Drivers/Simulink/STMpil_data.su ./Drivers/Simulink/rtGetInf.d ./Drivers/Simulink/rtGetInf.o ./Drivers/Simulink/rtGetInf.su ./Drivers/Simulink/rtGetNaN.d ./Drivers/Simulink/rtGetNaN.o ./Drivers/Simulink/rtGetNaN.su ./Drivers/Simulink/rt_nonfinite.d ./Drivers/Simulink/rt_nonfinite.o ./Drivers/Simulink/rt_nonfinite.su

.PHONY: clean-Drivers-2f-Simulink

