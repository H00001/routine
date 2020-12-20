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

routine_p acquire_routine(s_size_t len) {
    routine_p r = malloc(sizeof(routine_t));
    memset(r, 0, sizeof(routine_t));
    if (len > 0) {
        r->bs.stack = malloc(len * sizeof(data_t));
        r->bs.size = len;
    }
    return r;
}


