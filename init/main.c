/*
This code is public domain (no copyright).
*/
#include <system.h>
#include <vga.h>

void main()
{
    /* Agregar funciones de inicializacion aca! */
	console_color(WHITE/*color del caracter*/,RED/*color de fondo*/);
	console_clear();
	console_writes("Hola Mundo!");
    /* Este loop infinito sera el idle loop del sistema */
    for (;;);
}

