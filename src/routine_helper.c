#include "routine_helper.h"
#include "stack_collect.h"


void init_stack(routine_p r, any p, any stop) {
    r->bs.stack[r->bs.size - 1] = (code_t) stop;
    r->bs.stack[r->bs.size - 2] = (code_t) p;
    r->r.esp = (code_t) (r->bs.stack + r->bs.size - 2);
    r->r.ebp = (code_t) (r->bs.stack + r->bs.size - 1);
}

routine_p init_routine(comp uf, routine_p p_routine, data_p params, s_size_t stack_len) {
    routine_p r = acquire_routine(stack_len);
    set_rid(r);
    r->child = bit_new(ROUTINE_SUM);
    r->l.uf = uf;
    r->l.pid = p_routine == NULL ? -1 : p_routine->l.rid;
    if (p_routine != NULL)
        bit_set(p_routine->child, r->l.rid, true);
    if (params != NULL)
        set_init_params(&r->r.rdi, params);
    return r;
}

static rid_t set_rid(routine_p r) {
    static int curr_pid = 0;
    return r->l.rid = curr_pid++;
}

static void set_init_params(data_p p, data_p params) {
    memcpy(p, params, 6 * sizeof(data_t));
}