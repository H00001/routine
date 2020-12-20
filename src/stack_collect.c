//
// Created by dos frank on 11/15/20.
//

#include "stack_collect.h"

void release_routine(routine_p b) {
    if (b->bs.stack != NULL) {
        free(b->bs.stack);
    }
    free(b);
}

data_p acquire_stack0(int len) {
    return malloc(len * sizeof(data_t));
}

static data_p stack_from_collection() {
}