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


typedef struct Bits {
    unsigned long *bits;
    bit_size length;
    bit_size _length;
} *bitmap;


bitmap bit_new(bit_size length);

void bit_destroy(bitmap bit);

unsigned int bit_length(bitmap bit);

void bit_set(bitmap bit, unsigned int pos, unsigned char value);

char bit_get(bitmap bit, unsigned int pos);

bitmap bit_reset_0(bitmap bit);
