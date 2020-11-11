#include "routine.h"

proutine head;
proutine tail;
pcollect coll;
proutine ROUTINE_NR[1024];
#define SET_RET_U_ROUTINE \
    proutine r = create_routine0(p); \
    const uroutine u = {r->rid, &(r->rax), &(r->status)}; \


data_p stack_from_collection() {
    data_p s = coll->stack;
    coll = coll->link.next;
    return s;
}

data_p acquire_stack0(int len) {
    return coll == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection();
}

void set_rid(proutine r) {
    static int curr_pid = 0;
    ROUTINE_NR[r->rid = ++curr_pid] = r;
}

proutine create_routine0(any p) {
    ROUTINE_NR[0] = create_current_routine();
    proutine r = malloc(sizeof(routine));
    memset(r,0,sizeof(routine));
    set_rid(r);
    init_stack(&r, acquire_stack0(STACK_LEN), STACK_LEN, p);
    insert(&tail, r);
    return r;
}

uroutine create_routine_with_params(any p, int num, ...) {
    SET_RET_U_ROUTINE
    va_list valist;
    va_start(valist, num);
    data_p w = &(r->rdi);
    for (int i = 0; i < num; i++, w++) {
        (*w) = va_arg(valist, data_t);
    }
    va_end(valist);
    return u;
}

uroutine create_routine(any p) {
    SET_RET_U_ROUTINE
    return u;
}

proutine create_current_routine() {
    if (ROUTINE_NR[0] != NULL) {
        return ROUTINE_NR[0];
    }
    proutine r = malloc(sizeof(routine));
    r->rid = 0;
    return tail = head = r;
}

void remove_from_bitmap(rid_t rid){
    ROUTINE_NR[rid] = NULL;
}
