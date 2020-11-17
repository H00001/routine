//
// Created by dos frank on 11/15/20.
//

#include "stack_collect.h"

static reuse_p coll_s;
static reuse_p coll_e;

collect_p transfer_co(reuse_p p) {
    return (collect_p) (p);
}

void add_collect(base_stack b) {
    collect_p pc = malloc(sizeof(collect_t));
    pc->bs = b;
    insert_head(&coll_s, &coll_e, &pc->link);
}

data_p acquire_stack0(int len) {
    return coll_s == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection();
}

static data_p stack_from_collection() {
    collect_p pc = transfer_co(pop_head(&coll_s, &coll_e));
    data_p p = pc->bs.stack;
    free(pc);
    return p;
}