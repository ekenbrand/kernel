#ifndef __SYSTEM_H
#define __SYSTEM_H

typedef int size_t;
extern unsigned char *memcpy(void *dest, const void *src, size_t count);
extern unsigned char *memset(void *dest, int val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);
extern size_t strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

#endif
