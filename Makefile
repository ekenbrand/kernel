LD=ld
LDFLAGS=-Tlink.ld -ofooX

all:
		kernel main start link

kernel:
		(cd kernel; make)

main:
		(cd init; make) 

start:
		(cd boot; make)

link:
		$(LD) $(LDFLAGS) boot/start.o init/main.o kernel/system.o

clean:
	(cd kernel; make clean)
	(cd init; make clean)
	(cd boot; make clean)
	rm -f fooX
