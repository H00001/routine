#include "routine.h"
proutine head;
proutine tail;

void set_head_tail(proutine h,proutine t){
	head = h;
	tail = t;
}

void exchange_c(proutine* h,proutine* t){
    proutine curr = head;
    proutine n = head->next;
    curr->next = NULL;
    tail->next = curr;
    tail = curr;
    head = n;
}

proutine create_routine(any p,proutine next) {
    proutine r = malloc(sizeof(routine));
    r->stack = malloc(STACK_LEN*sizeof(data_t));
    r->stack[STACK_LEN - 1] = (code_t) p;
    r->esp = (code_t) (r->stack + STACK_LEN - 1);
    r->ebp = (code_t) (r->stack + STACK_LEN);
    r->next = next;
    return r;
}

proutine create_empty_routine(proutine next) {
    proutine r = malloc(sizeof(routine));
    r->next = next;
    return r;
}
