//
// Created by dos DRTT on 11/15/20.
//

#ifndef ROUTINE_STACK_COLLECT_H
#define ROUTINE_STACK_COLLECT_H

#include "routine_common.h"

typedef struct _collect {
    reuse_t link;
    base_stack bs;
} collect_t, *collect_p;

collect_p transfer_co(reuse_p p);

void add_collect(base_stack b);

static data_p stack_from_collection();

data_p acquire_stack0(int len);

#endif //ROUTINE_STACK_COLLECT_H
