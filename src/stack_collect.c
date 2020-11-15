//
// Created by dos DRTT on 11/15/20.
//

#include "stack_collect.h"

static preuse colls;
static preuse colle;

pcollect transfer_co(preuse p) {
    return (pcollect) (p);
}

void add_collect(base_stack b) {
    pcollect pc = malloc(sizeof(collect));
    pc->bs = b;
    insert_head(&colls, &colle, &pc->link);
}

data_p acquire_stack0(int len) {
    return colls == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection();
}

static data_p stack_from_collection() {
    pcollect pc = transfer_co(pop_head(&colls, &colle));
    data_p p = pc->bs.stack;
    free(pc);
    return p;
}