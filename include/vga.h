#ifndef _VGA_H_
#define _VGA_H_

#include <stdint.h>


#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define LiGHT_GREY 0x07
#define DARK_GREY 0x08
#define LIGHT_BLUE 0x09
#define LIGHT_GREEN 0x0A
#define LIGHT_CYAN 0x0B
#define LIGHT_RED 0x0C
#define LIGHT_MAGENTA 0x0D
#define LIGHT_BROWN 0x0E
#define WHITE 0x0F


void console_clear();
void move_cursor();
void hide_cursor();
void unhide_cursor();
void console_writes(char *string);
void console_writec(char c);
void console_color( uint8_t foreground, uint8_t background);

#endif
