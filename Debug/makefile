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
LM35_IOT_ESP.lss \

FLASH_IMAGE += \
LM35_IOT_ESP.hex \

EEPROM_IMAGE += \
LM35_IOT_ESP.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LM35_IOT_ESP.elf secondary-outputs

# Tool invocations
LM35_IOT_ESP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LM35_IOT_ESP.map -mmcu=atmega32 -o "LM35_IOT_ESP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LM35_IOT_ESP.lss: LM35_IOT_ESP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LM35_IOT_ESP.elf  >"LM35_IOT_ESP.lss"
	@echo 'Finished building: $@'
	@echo ' '

LM35_IOT_ESP.hex: LM35_IOT_ESP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LM35_IOT_ESP.elf  "LM35_IOT_ESP.hex"
	@echo 'Finished building: $@'
	@echo ' '

LM35_IOT_ESP.eep: LM35_IOT_ESP.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LM35_IOT_ESP.elf  "LM35_IOT_ESP.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LM35_IOT_ESP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LM35_IOT_ESP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LM35_IOT_ESP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
