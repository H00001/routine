#include "routine_helper.h"


void init_stack(routine_p r, data_p stack, int len, any p, any stop) {
    r->bs.stack = stack;
    r->bs.size = len;
    stack[len - 1] = (code_t) stop;
    stack[len - 2] = (code_t) p;
    r->esp = (code_t) (stack + len - 2);
    r->ebp = (code_t) (stack + len - 1);
}

routine_p init_routine() {
    routine_p r = malloc(sizeof(routine_t));
    memset(r, 0, sizeof(routine_t));
    return r;
}

rid_t set_rid(routine_p r) {
    static int curr_pid = 0;
    return r->rid = ++curr_pid;
}