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

proutine init_routine() {
    proutine r = malloc(sizeof(routine));
    memset(r, 0, sizeof(routine));
    return r;
}

proutine create_routine0(any p) {
    ROUTINE_NR[0] = create_current_routine();
    proutine r = init_routine();
    set_rid(r);
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p);
    insert(&tail, r);
    return r;
}

uroutine create_routine_with_params(any p, int num, ...) {
    SET_RET_U_ROUTINE
    va_list p_list;
    va_start(p_list, num);
    data_p w = &(r->rdi);
    for (int i = 0; i < num; i++, w++) {
        (*w) = va_arg(p_list, data_t);
    }
    va_end(p_list);
    return u;
}

uroutine create_routine(any p) {
    SET_RET_U_ROUTINE
    return u;
}

proutine create_current_routine() {
    return ROUTINE_NR[0] != NULL ? ROUTINE_NR[0] : (tail = head = init_routine());
}

void remove_from_bitmap(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}
