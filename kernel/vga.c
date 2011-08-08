/*
This code is public domain (no copyright).

Controlador basico de video VGA (Video Graphic Array) para modo texto 80x25
http://www.osdever.net/FreeVGA/home.htm
*/
#include <vga.h>
#include <system.h>

#define VGA_CRT_INDEX 0x3D4 //CRT Controller Index/Address Register
#define VGA_CRT_DATA 0x3D5 //CRT Controller Data Register
#define CURSOR_HIGH_REG 0x0E //Cursor Location High Register, byte de mayor peso
#define CURSOR_LOW_REG 0x0F //Cursor Location Low Register, byte de menor peso
#define VIDEO_MEMORY_ADDR 0xB8000 //Direccion del framebuffer de video

uint8_t cursor_row;
uint8_t cursor_col;
uint16_t attribute = ((RED << 4) | WHITE) << 8;

/*
Mueve el cursor a la posicion dada por el par (row,col) solo para modo 
texto(80*25)
*/
void move_cursor()
{
	//TODO verificar limites
	uint16_t position = (cursor_row * 80) + cursor_col;//Tener cuidado con el endianness
	outport(VGA_CRT_INDEX, CURSOR_HIGH_REG);
	outport(VGA_CRT_DATA, position >> 8);
	outport(VGA_CRT_INDEX, CURSOR_LOW_REG);
	outport(VGA_CRT_DATA, position);	
}

/*
Borra la pantalla copiando espacios al framebuffer
*/
void console_clear()
{
	uint16_t blank = 0x20/*espacio*/| attribute;/*caracter + atributos*/
	//Escribo todo el framebuffer con el espacio en blanco
	//TODO verificar cual de los dos llamados es mas eficiente
	/*	
	for (int i = 0; i < 80*25; i++)
		((uint16_t*)VIDEO_MEMORY_ADDR)[i] = blank;
	*/
	memsetw((void*)VIDEO_MEMORY_ADDR, blank, 80*25);
  	//Muevo el cursor de vuelta al principio
	cursor_row = cursor_col = 0;
  	move_cursor();
}

/*
Esconde el cursor
*/
void hide_cursor()
{
	outport(VGA_CRT_INDEX, 0x0A);
	outport(VGA_CRT_DATA, 0x10);
}

/*
Muestra el cursor
*/
void unhide_cursor()
{
	outport(VGA_CRT_INDEX, 0x0A);
	outport(VGA_CRT_DATA, 0x0F);
}

/*
Escribe la cadena de caracteres
*/
void console_writes(char *string)
{
	for(int i = 0;string[i] != '\0'; i++)
		console_writec(string[i]);
}

/*
Define el color de la letra y el fondo
*/
void console_color( uint8_t foreground, uint8_t background)
{
	attribute =  (background << 4) | foreground;
	attribute = attribute << 8;
}
/*
Imprime el caracter pasado como parametro
*/
void console_writec(char c)
{
	/*
	caracteres a manejar de manera especial: espacio, backspace, enter, 
fin de linea, no se me ocurre otro
	*/
	uint16_t* pos = (uint16_t*)VIDEO_MEMORY_ADDR + (cursor_row*80 + cursor_col);
	uint8_t blank = 0x20;
	switch(c){
		case '\n': cursor_row = 0;
					++cursor_col;
					break;
		case '\b': --cursor_row;/*backspace*/
					c = blank;
					break;
		default: ++cursor_col;
					break;
	}//TODO revisar esta parte, no esta bien
	if(cursor_col >= 80){//bajo una linea
		cursor_col = 0;
		++cursor_row;
		if(cursor_row >= 25){//se lleno el framebuffer, saco la primer linea
			//muevo todo el framebuffer una linea para atras
			memcpy((void *)VIDEO_MEMORY_ADDR, (void *)VIDEO_MEMORY_ADDR + (80 * 2), 80 * 24 * 2);
			//borro la ultima linea del framebuffer
			memsetw((void *)VIDEO_MEMORY_ADDR + (80*24*2), blank | attribute, 80);
			--cursor_row;
		}
	}
	*pos = c | attribute;
	move_cursor();
}
