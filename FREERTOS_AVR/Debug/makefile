################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FreeRTOS_Driver.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: FreeRTOS_Driver.elf secondary-outputs

# Tool invocations
FreeRTOS_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FreeRTOS_Driver.map -mmcu=atmega16 -o "FreeRTOS_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FreeRTOS_Driver.lss: FreeRTOS_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FreeRTOS_Driver.elf  >"FreeRTOS_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FreeRTOS_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 FreeRTOS_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FreeRTOS_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
