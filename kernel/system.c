/*
This code is public domain (no copyright).
*/
#include <system.h>

/*
Copia una cantidad count de memoria a partir de la posicion dest desde la 
posicion src. Estas posiciones no deben superponerse
*/
unsigned char *memcpy(void *dest, const void *src, size_t count)
{
    for(int i = 0; i < count; i++)
    	*((char *)dest + i) = *((char *)src + i);
    return dest;
}

/*
Cambia el valor de la memoria desde la posicion dest hasta dest+count por el 
valor val
*/
unsigned char *memset(void *dest, int val, size_t count)
{
    char *temp = (char *)dest;
	for( ; count != 0; count--)	
		*temp++ = val;
    return dest;
}

/*
Igual a la anterior pero solo para 16-bits
*/
unsigned short *memsetw(void *dest, uint16_t val, size_t count)
{
    for(int i = 0; i < count; i++)
    	*((uint16_t *)dest + i) = val;
    return dest;
}

/*
Devuelve la cantidad de bytes que hay desde la posicion str hasta que 
encuentre un '/0'. En otras palabras el largo de la cadena
*/
size_t strlen(const char *str)
{
	size_t count;
	for( count = 0; *str != '\0'; ++str) ++count;
	return count;
}

/*
Lee un byte desde el puerto _port
*/
uint8_t inport(uint16_t _port)
{
    uint8_t rv;
    __asm__ __volatile__ ("in %%dx, %%al" : "=a" (rv) : "d" (_port));
    return rv;
}

/*
Escribe al puerto _port el byte _data
*/
void outport(uint16_t _port, uint8_t _data)
{
    __asm__ __volatile__ ("out %%al, %%dx" : : "a" (_data), "d" (_port));
}


