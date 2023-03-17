//
// Created by dos frank on 11/15/20.
//

#include "./include/stack_collect.h"


static reuse_p head = NULL;
static reuse_p tail = NULL;

void release_routine(routine_p b) {
    re_init(b);
    insert_tail(&head, &tail, &b->u);
}

static void re_init(routine_p r) {
    if (r->bs.stack != NULL) {
        free(r->bs.stack);
        r->bs.stack = NULL;
    }
    memset(r, 0, sizeof(registers));
    r->child = r->child == NULL ? bit_new(ROUTINE_SUM) : bit_reset_0(r->child);
    memset(&(r->l), 0, sizeof(det));
};

routine_p acquire_routine(s_size_t len) {
    routine_p r = head != NULL ? transfer_eo(pop_head(&head, &tail)) : malloc(sizeof(routine_t));
    memset(r, 0, sizeof(routine_t));
    if (len > 0) {
        r->bs.stack = malloc(len * sizeof(data_t));
        r->bs.size = len;
    }
    return r;
}


