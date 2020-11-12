#include "routine.h"

void remove(proutine *h, pcollect *c,uroutine** u) {
    pcollect t = malloc(sizeof(collect));
    uroutine* u1 = malloc(sizeof(uroutine));
    t->bs = (*h)->bs;

    if ((*c) != NULL) {
        t->link.next = (pcollect) (*c);
    }
    (*c) = t;

    u1->consequence = (*h)->rax;
    u1->status = T;
    u[u1->rid=(*h)->rid]=u1;
    remove_from_bitmap((*h)->rid);

    proutine lh = (*h);
    (*h) = (*h)->next;
    free(lh);
}

void exchange_c(proutine *h, proutine *t) {
    proutine n = (*h)->next;
    if (n == NULL) {
        return;
    }
    n->status = R;
    proutine curr = (*h);
    curr->next = NULL;
    (*t)->next = curr;
    (*t) = curr;
    (*h) = n;
}

void init_stack(proutine r, data_p stack, int len, any p) {
    r->bs.stack = stack;
    r->bs.size = len;
    stack[len - 1] = (code_t) stop_routine;
    stack[len - 2] = (code_t) p;
    r->esp = (code_t) (stack + STACK_LEN - 2);
    r->ebp = (code_t) (stack + STACK_LEN - 1);
}

void insert(proutine *n, proutine r) {
    (*n) = (*n)->next = r;
}
