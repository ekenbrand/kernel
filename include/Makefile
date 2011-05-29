CC=gcc
CFLAGS	= -c -std=c99 -Wall -O -fstrength-reduce -fomit-frame-pointer  \
	-finline-functions -nostdinc -fno-builtin -I../include

system.o:
		$(CC) $(CFLAGS) system.c

clean:
	rm -f *.o
