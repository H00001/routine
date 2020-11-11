#include "routine_base.h"

proutine head;
proutine tail;
static pcollect coll;
proutine ROUTINE_NR[ROUTINE_SUM];
uroutine *UROUTINE_NR[ROUTINE_SUM];


base_stack stack_from_collection() {
    base_stack s = coll->bs;
    pcollect pc = coll;
    coll = coll->link.next;
    free(pc);
    return s;
}

static data_p acquire_stack0(int len) {
    return coll == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection().stack;
}

void set_rid(proutine r) {
    static int curr_pid = 0;
    ROUTINE_NR[r->rid = ++curr_pid] = r;
}

proutine create_routine0(any p) {
    ROUTINE_NR[0] = create_current_routine();
    proutine r = init_routine();
    set_rid(r);
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p, stop_routine);
    tail = tail->next = r;
    return r;
}

static proutine create_current_routine() {
    return ROUTINE_NR[0] != NULL ? ROUTINE_NR[0] : (tail = head = init_routine());
}

static void remove_from_routine_list(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}

void remove_0() {
    pcollect t = malloc(sizeof(collect));
    uroutine *u1 = malloc(sizeof(uroutine));
    t->bs = head->bs;

    if (coll != NULL) {
        t->link.next = (pcollect) coll;
    }
    coll = t;

    u1->consequence = head->rax;
    u1->status = T;
    UROUTINE_NR[u1->rid = head->rid] = u1;
    remove_from_routine_list(head->rid);

    proutine lh = head;
    head = head->next;
    free(lh);
}