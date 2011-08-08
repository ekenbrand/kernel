#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdint.h>


/* Define a size type */
typedef int size_t;


unsigned char *memcpy(void *dest, const void *src, size_t count);
unsigned char *memset(void *dest, int val, size_t count);
unsigned short *memsetw(void *dest, uint16_t val, size_t count);
size_t strlen(const char *str);
uint8_t inport(uint16_t _port);
void outport(uint16_t _port, uint8_t _data);

#endif
