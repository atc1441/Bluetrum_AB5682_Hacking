# Makefile
TARGET = firmware
CC = xpack-riscv-none-embed-gcc/bin/riscv-none-embed-gcc
OBJCOPY = xpack-riscv-none-embed-gcc/bin/riscv-none-embed-objcopy

# Architektur-Flags
ARCH_FLAGS = -march=rv32imc -mabi=ilp32 -g

# Compiler-Flags
CFLAGS = $(ARCH_FLAGS) -fPIC -Wall

# Linker-Flags
LDFLAGS = $(ARCH_FLAGS) -nostartfiles --specs=nano.specs -T ram.ld -Wl,-Map,$(TARGET).map

# Quelldateien
SRCS = main.c util.c startup.s
LOCAL_OBJS = $(SRCS:.c=.o)
LOCAL_OBJS := $(LOCAL_OBJS:.s=.o)
PRECOMPILED_OBJS = $(wildcard libs/*.o)
OBJS = $(LOCAL_OBJS) $(PRECOMPILED_OBJS)

.PHONY: all clean

all: $(TARGET).bin

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LOCAL_OBJS) $(TARGET).elf $(TARGET).bin $(TARGET).map

upload:
	python upload_fw_to_ram.py --port COM33 --loader $(TARGET).bin