CC=gcc
CFLAGS	= -c -std=c99 -Wall -O -fstrength-reduce -fomit-frame-pointer  \
	-finline-functions -nostdinc -fno-builtin -I../include

main.o:
		$(CC) $(CFLAGS) main.c 

clean:
	rm -f *.o
