//
// Created by dos DRTT on 11/18/20.
//

#ifndef ROUTINE_BITMAP_H
#define ROUTINE_BITMAP_H

#endif //ROUTINE_BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long bit_size;

typedef struct _Bits {
    unsigned long *bits;
    bit_size length;
    bit_size _length;
} *bits;


bits bit_new(bit_size length);

void bit_destroy(bits bit);

unsigned int bit_length(bits bit);

void bit_set(bits bit, unsigned int pos, unsigned char value);

char bit_get(bits bit, unsigned int pos);