#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

void set_value(char * ptr, unsigned int index, char value);
void clear_value(char * ptr, unsigned int index);
char get_value(char * ptr, unsigned int index);
void set_all(char * ptr, char value, unsigned int size);
void clear_all(char * ptr, unsigned int size);

#endif
