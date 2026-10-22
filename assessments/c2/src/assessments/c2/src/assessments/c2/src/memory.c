#include "memory.h"

void set_value(char * ptr, unsigned int index, char value) {
    ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index) {
    set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index) {
    return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        ptr[i] = value;
    }
}

void clear_all(char * ptr, unsigned int size) {
    set_all(ptr, 0, size);
}
