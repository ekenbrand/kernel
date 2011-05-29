CC=gcc
CFLAGS	= -c -std=c99 -Wall -O -fstrength-reduce -fomit-frame-pointer  \
	-finline-functions -nostdinc -fno-builtin -I../include
#Compila para la arquitectura i386
CFLAGS +=-m32
main.o: ../include/system.h main.c
	$(CC) $(CFLAGS) main.c 

clean:
	rm -f *.o
