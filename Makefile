# Nombre del kernel
target := fooOS

CC := gcc
LD := ld
AS := nasm

WARNINGS := -Wall -Wextra -fstrength-reduce -fomit-frame-pointer \
			-finline-functions -nostdinc -fno-builtin
CFLAGS := -std=c99 -I./include -m32 $(WARNINGS)
LDFLAGS := -T link.ld
ASFLAGS := -f elf


PROJDIRS := kernel init boot
SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c")
ASFILES := $(shell find $(PROJDIRS) -type f -name "*.asm")
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES)) 
OBJFILES := $(patsubst %.asm,%.o,$(ASFILES)) $(OBJFILES)
DEPFILES := $(patsubst %.c,%.d,$(SRCFILES))

all: $(target)

$(target): $(OBJFILES)
	@$(LD) $(LDFLAGS) $(OBJFILES) -o $(target)

boot/start.o:
	@$(AS) $(ASFLAGS) $(ASFILES) -o $@

#-include $(DEPFILES)
%.o: %.c $(DEPFILES) Makefile
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	-@$(RM) $(OBJFILES) $(target) 
