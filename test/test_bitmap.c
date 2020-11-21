//
// Created by dos DRTT on 11/18/20.
//

#include "../src/bitmap.h"
#include "./unit_test.h"

int main() {
    bits b = bit_new(110);

    for (int i = 0; i <100 ; ++i) {
        bit_set(b, i, 1);
        test_eq(bit_get(b, i), 1);
    }
    for (int i = 0; i <100 ; ++i) {
        bit_set(b, i, 0);
        test_eq(bit_get(b, i), 0);
    }

}