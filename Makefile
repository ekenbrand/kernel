# Nombre del kernel
target = fooOS
LD=ld
LDFLAGS= -Tlink.ld
OBJS= boot/start.o init/main.o kernel/system.o

all: $(target)
kernel/system.o:
	(cd kernel; make)
init/main.o:
	(cd init; make) 
boot/start.o:
	(cd boot; make)
$(target): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(target)
clean:
	rm $(OBJS) $(target) 
