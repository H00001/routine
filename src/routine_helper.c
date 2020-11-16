#include "routine_helper.h"


void init_stack(proutine r, data_p stack, int len, any p, any stop) {
    r->bs.stack = stack;
    r->bs.size = len;
    stack[len - 1] = (code_t) stop;
    stack[len - 2] = (code_t) p;
    r->esp = (code_t) (stack + len - 2);
    r->ebp = (code_t) (stack + len - 1);
}

proutine init_routine() {
    proutine r = malloc(sizeof(routine));
    memset(r, 0, sizeof(routine));
    return r;
}

rid_t set_rid(proutine r) {
    static int curr_pid = 0;
    return r->rid = ++curr_pid;
}