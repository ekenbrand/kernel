CC=gcc
CFLAGS	= -c -std=c99 -Wall -O -fstrength-reduce -fomit-frame-pointer  \
	-finline-functions -nostdinc -fno-builtin -I../include
#Compila para la arquitectura i386
CFLAGS +=-m32
system.o: ../include/system.h system.c
	$(CC) $(CFLAGS) system.c

clean:
	rm -f *.o
