#include "routine_helper.h"


void exchange_c(proutine *h, proutine *t) {
    proutine n = *h;
    proutine f = NULL, e = NULL;
    for (; ((n = n->next) == NULL) || (n->status == UB);) {
        if (n == NULL) {
            return;
        }
        f = f == NULL ? n : f;
        e = n;
    }
    if (e != NULL) {
        e->next = NULL;
    }
    n->status = R;
    proutine curr = (*h);
    curr->next = f;
    (*t)->next = curr;
    (*t) = e == NULL ? curr : e;
    (*h) = n;
}

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
