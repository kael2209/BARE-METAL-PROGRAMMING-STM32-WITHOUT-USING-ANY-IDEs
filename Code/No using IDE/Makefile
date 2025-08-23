CC = arm-none-eabi-gcc
MARC = cortex-m3
INC_DIR := Core/Inc
LD_FILE := Linker/linker.ld

CCFLAGS = -c -mcpu=$(MARC) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
LDFLAGS = -T$(LD_FILE) -nostdlib -Wl,-Map=Build/main.Map

OBJCOPY = arm-none-eabi-objcopy

PROGRAMMER := ./Programmer/ST_LINK_Utility/ST-LINK_CLI

all: folder Flash/main.hex Flash/main.bin
	@echo "	Build done!"
	@echo "[✓]Generated HEX: main.hex"
	@echo "[✓]Generated BIN: main.bin"

folder:
	@mkdir -p Build
	@mkdir -p Flash	
Build/main.o: Core/Src/main.c
	@$(CC) $(CCFLAGS) -o $@ $^
Build/startup.o: Startup/startup.c
	@$(CC) $(CCFLAGS) -o $@ $^
Build/main.elf: Build/main.o Build/startup.o
	@$(CC) $(LDFLAGS) -o $@ $^
Flash/main.hex: Build/main.elf
	@$(OBJCOPY) -O ihex $^ $@
Flash/main.bin: Build/main.elf
	@$(OBJCOPY) -O binary $^ $@

erase:
	@echo "[🧹] Erasing chip..."
	@$(PROGRAMMER) -ME
	@echo "[🧹] Chip erased."

load:
	@echo "[📤] Loading program to STM32..."
	@$(PROGRAMMER) -p "Flash/main.hex" 0x08000000
	@echo "Load done!"

reset:
	@echo "[🔄] Resetting chip..."
	@$(PROGRAMMER) -rst
	@echo "[✓] Reset done!"

clean:
	@rm -rf Build Flash
	@echo "[✓] Clean done!"
	