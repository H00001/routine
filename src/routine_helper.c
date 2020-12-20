#include "routine_helper.h"


void init_stack(routine_p r, data_p stack, int len, any p, any stop) {
    r->bs.stack = stack;
    r->bs.size = len;
    stack[len - 1] = (code_t) stop;
    stack[len - 2] = (code_t) p;
    r->r.esp = (code_t) (stack + len - 2);
    r->r.ebp = (code_t) (stack + len - 1);
}

routine_p init_routine(comp uf, routine_p p_routine, data_p params, s_size_t stack_len) {
    routine_p r = malloc(sizeof(routine_t));
    memset(r, 0, sizeof(routine_t));
    set_rid(r);
    r->child = bit_new(ROUTINE_SUM);
    r->uf = uf;
    r->pid = p_routine == NULL ? -1 : p_routine->rid;
    if (p_routine != NULL)
        bit_set(p_routine->child, r->rid, true);
    if (params != NULL)
        set_init_params(&r->r.rdi, params);
    return r;
}

static rid_t set_rid(routine_p r) {
    static int curr_pid = 0;
    return r->rid = curr_pid++;
}

static void set_init_params(data_p p, data_p params) {
    memcpy(p, params, 6 * sizeof(data_t));
}