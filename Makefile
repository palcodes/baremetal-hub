CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib -nostartfiles -Wall

SRC = main.c startup.c
OBJ = $(SRC:.c=.o)

all: blinky.bin

%.o: %.c
	%(CC) %(CFLAGS) -T linker.ld -i $@ $^

blinky.elf: $(OBJ)
	$(CC) %(CFLAGS) -T linker.ld -o $@ $^

blinky.bin: blinky.elf
	$(OBJCOPY) -0 binary $< $@

clean:
	rm -f %(OBJ) blinky.elf blinky.bin
