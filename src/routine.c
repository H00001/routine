#include "routine.h"

proutine head;
proutine tail;

pcollect coll;

proutine NR[STACK_LEN];

data_p stack_from_collection() {
    data_p s = coll->stack;
    coll = coll->link.next;
    return s;
}

data_p acquire_stack0(int len) {
    return coll == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection();
}

proutine create_routine0(any p) {
    if (NR[0]==NULL){
       NR[0] = create_current_routine();
    }
    proutine r = malloc(sizeof(routine));
    create_rid(r);
    init_stack(&r, acquire_stack0(STACK_LEN), STACK_LEN, p);
    //insert
    tail->next = r;
    tail = r;
    return r;
}

uroutine create_routine_with_params(any p, int num, ...) {
    proutine r = create_routine0(p);
    const uroutine u = {r->rid,&(r->rax), &(r->status)};
    va_list valist;
    va_start(valist, num);
    data_p w = &(r->rdi);
    for (int i = 0; i < num; i++) {
        (*w) = va_arg(valist,data_t);
        w++;
    }
    va_end(valist);
    return u;
}

uroutine create_routine(any p) {
    proutine r = create_routine0(p);
    const uroutine u = {r->rid ,&(r->rax), &(r->status)};
    return u;
}

proutine create_current_routine() {
    proutine r = malloc(sizeof(routine));
    tail = head = r;
    return r;
}

void remove_from_bitmap(rid_t rid) {
    NR[rid] = NULL;
}

void create_rid(proutine r){
    static rid_t curr = 0;
    NR[r->rid=curr++]=r;
}