################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../media/material/programs/Example_FresnelPS.asm 

OBJS += \
./media/material/programs/Example_FresnelPS.o 


# Each subdirectory must supply rules for building sources it contributes
media/material/programs/%.o: ../media/material/programs/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


