ToolChain = arm-none-eabi-
CPU = -mcpu=cortex-m4 -mthumb
LF = linker_file.ld
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

ALL: app.hex
	@echo "_^^Build is Done^^_"
%.o : %.c
	$(ToolChain)gcc -c $(CPU) $< -o $@

app.elf : $(OBJ)
	$(ToolChain)ld -Map app.map -T $(LF) $^ -o $@

app.hex : app.elf
	$(ToolChain)objcopy -O ihex $< $@

clean:
	rm *.asm *.elf *.o *.hex *.map
