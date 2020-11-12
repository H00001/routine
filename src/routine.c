#include "routine.h"

proutine head;
proutine tail;
pcollect coll;
proutine ROUTINE_NR[1024];
uroutine* UROUTINE_NR[1024];


base_stack stack_from_collection() {
    base_stack s = coll->bs;
    pcollect pc = coll;
    coll = coll->link.next;
    free(pc);
    return s;
}

data_p acquire_stack0(int len) {
    return coll == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection().stack;
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

rid_t create_routine_with_params(any p, int num, ...) {
    proutine r = create_routine0(p);
    va_list p_list;
    va_start(p_list, num);
    data_p w = &(r->rdi);
    for (int i = 0; i < num; i++, w++) {
        (*w) = va_arg(p_list, data_t);
    }
    va_end(p_list);
    return r->rid;
}

rid_t create_routine(any p) {
    return create_routine0(p)->rid;
}

proutine create_current_routine() {
    return ROUTINE_NR[0] != NULL ? ROUTINE_NR[0] : (tail = head = init_routine());
}

void remove_from_bitmap(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}

data_t get_consequence(rid_t rid){
    return UROUTINE_NR[rid]->consequence;
}

STATUS get_status(rid_t rid){
    return UROUTINE_NR[rid]->status;
}