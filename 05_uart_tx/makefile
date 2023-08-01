PROJECT_NAME = blink
BOARD = STM32F446xx
MCU = cortex-m4

SOURCE = ./src
STM32F446RE = ../STM32F446RE
BUILD = ./build
STARTUP = ../STM32F446RE/startup_stm32f446xx.s
SYSTEM = ../STM32F446RE/system_stm32f4xx.c
LINKERSCRIPT = ../STM32F446RE/STM32F446RETX_FLASH.ld
CMSIS_INCLUDES_DIR = ../STM32F446RE/Core/Include
#STLINK_DIR = ../stlink/bin

SRCS = $(SOURCE)/main.c \
	$(STM32F446RE)/syscalls.c

SRCS += $(STARTUP)
SRCS += $(SYSTEM)

CFLAGS = -g -O2 -Wall -T $(LINKERSCRIPT)
CFLAGS += -mlittle-endian -mthumb -mcpu=$(MCU) -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += --specs=nosys.specs
CFLAGS += -I $(CMSIS_INCLUDES_DIR)
CFLAGS += -I $(STM32F446RE)


compile: ${BUILD}
	arm-none-eabi-gcc $(CFLAGS) $(SRCS) -o $(BUILD)/$(PROJECT_NAME).elf -D$(BOARD)
	arm-none-eabi-objcopy -O ihex $(BUILD)/$(PROJECT_NAME).elf $(BUILD)/$(PROJECT_NAME).hex
	arm-none-eabi-objcopy -O binary $(BUILD)/$(PROJECT_NAME).elf $(BUILD)/$(PROJECT_NAME).bin

upload:
	$(STLINK_DIR)/st-flash --reset write $(BUILD)/$(PROJECT_NAME).bin 0x8000000

jflash: ../STM32F446RE/jflash.jlink
	JLinkExe -CommanderScript $<

all: ${BUILD} compile jflash 

${BUILD}:
	@mkdir ${BUILD}

clean:
	rm -rf $(BUILD) 
#/$(PROJECT_NAME).elf $(BUILD)/$(PROJECT_NAME).hex $(BUILD)/$(PROJECT_NAME).bin