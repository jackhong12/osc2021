# cross-compiler
COMPILER := aarch64-linux-gnu-gcc
LINKER := aarch64-linux-gnu-ld
OBJCOPY := aarch64-linux-gnu-objcopy
QEMU := qemu-system-aarch64

DIR := src
BUILD_DIR := build
C_SRC := $(wildcard $(DIR)/*.c)
C_OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(C_SRC)))
ASM_SRC := $(wildcard $(DIR)/*.S)
ASM_OBJ := $(patsubst %.S, $(BUILD_DIR)/%.o, $(notdir $(ASM_SRC)))
LD := ../linker.ld


# flag
#CCFLAG := -Wall -ffreestanding -nostdinc -nostdlib -nostartfiles -Og -g -Iinclude
CCFLAG := -Wall -ffreestanding -nostdinc -nostdlib -nostartfiles -Og -g -Iinclude -I../src

all: $(C_OBJ) $(ASM_OBJ)

$(BUILD_DIR)/%.o: $(DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(COMPILER) $(CCFLAG) -c $< -o $@

$(BUILD_DIR)/%.o: $(DIR)/%.S
	@mkdir -p $(BUILD_DIR)
	$(COMPILER) $(CCFLAG) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
