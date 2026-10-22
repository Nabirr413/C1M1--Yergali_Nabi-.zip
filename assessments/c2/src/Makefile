#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#*****************************************************************************

#------------------------------------------------------------------------------
# Build System for Host (native gcc) and MSP432 (arm-none-eabi-gcc)
#------------------------------------------------------------------------------
include sources.mk

PLATFORM ?= HOST
TARGET = c1m2

GEN_FLAGS = -Wall \
            -Werror \
            -g \
            -O0 \
            -std=c99

ifeq ($(PLATFORM),MSP432)
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  SIZE = arm-none-eabi-size
  OBJDUMP = arm-none-eabi-objdump

  CPU = cortex-m4
  ARCH = armv7e-m
  SPECS = nosys.specs
  FLOAT = hard
  FPU = fpv4-sp-d16
  ARM_FLAGS = -mcpu=$(CPU) \
              -mthumb \
              -march=$(ARCH) \
              -mfloat-abi=$(FLOAT) \
              -mfpu=$(FPU) \
              --specs=$(SPECS)

  LINKER_FILE = ../msp432p401r.lds
  LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

  CPPFLAGS = -DMSP432 $(INCLUDES)
  CFLAGS = $(GEN_FLAGS) $(ARM_FLAGS)
else
  CC = gcc
  LD = ld
  SIZE = size
  OBJDUMP = objdump

  LDFLAGS = -Wl,-Map=$(TARGET).map
  CPPFLAGS = -DHOST $(INCLUDES)
  CFLAGS = $(GEN_FLAGS)
endif

OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)
DEPS = $(SOURCES:.c=.d)

-include $(DEPS)

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $< > $@

%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -MMD -MP -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map $(TARGET).asm
