//
// Created by dos DRTT on 11/18/20.
//

#include "bitmap.h"


bitmap bit_new(bit_size length) {
    bitmap new_bits = malloc(sizeof(struct _Bits));
    if (new_bits == NULL)
        return NULL;

    new_bits->_length = (length >> 6) + 1;
    new_bits->bits = malloc(sizeof(char) * new_bits->_length);
    memset(new_bits->bits, 0, new_bits->_length);
    new_bits->length = length;
    return new_bits;
}

void bit_destroy(bitmap bit) {
    free(bit->bits);
    free(bit);
}

unsigned int bit_length(bitmap bit) {
    return bit->length;
}

void bit_set(bitmap bit, unsigned int pos, unsigned char value) {
    unsigned long mask = 1 << (pos & 63);
    bit->bits[(pos >> 6)] = value ? bit->bits[(pos >> 6)] | mask :
                            bit->bits[(pos >> 6)] & ~mask;
}

char bit_get(bitmap bit, unsigned int pos) {
    unsigned long mask = 1 << (pos & 63);
    return (mask & bit->bits[(pos >> 6)]) > 0 ? 1 : 0;
}


unsigned long get_zero(bitmap b) {
    for (unsigned long i = 0; i < b->_length; i++) {
        if (~(b->bits[i]) > 0) {
            for (int j = 0; j < 64; j++) {
                if (!bit_get(b, j)) {
                    return (i << 6) + j;
                }
            }
        }
    }
}