#include "routine.h"

void remove(proutine *h, pcollect *c) {
    pcollect t = malloc(sizeof(collect));
    t->stack = (*h)->stack;
    if ((*c) != NULL) {
        t->link.next = (pcollect) (*c);
    }
    (*c) = t;

    (*h)->status = T;
    (*h)->stack = NULL;
    remove_from_bitmap((*h)->rid);
    (*h) = (*h)->next;
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

void init_stack(proutine *r, data_p stack, int len, any p) {
    (*r)->stack = stack;
    stack[len - 1] = (code_t) stop_routine;
    stack[len - 2] = (code_t) p;
    (*r)->esp = (code_t) ((*r)->stack + STACK_LEN - 2);
    (*r)->ebp = (code_t) ((*r)->stack + STACK_LEN - 1);
}

void insert(proutine *n, proutine r) {
    (*n)->next = r;
    (*n) = r;
}
