#include "routine_base.h"

preuse head;
preuse tail;
static preuse event_queue_h = NULL;
static preuse event_queue_r = NULL;
static preuse ub_head;
static preuse ub_tail;
proutine ROUTINE_NR[ROUTINE_SUM];
uroutine UROUTINE_NR[ROUTINE_SUM];

proutine create_routine0(any p) {
    create_current_routine();
    proutine r = init_routine();
    ROUTINE_NR[set_rid(r)] = r;
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p, stop_routine);
    insert_tail(&head, &tail, &r->u);
    return r;
}

static proutine create_current_routine() {
    if (ROUTINE_NR[0] == NULL) {
        proutine p = init_routine();
        insert_head(&head, &tail, &p->u);
        ROUTINE_NR[0] = p;
    }
    return ROUTINE_NR[0];
}

static void remove_from_routine_list(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}

void remove_0() {
    proutine p = transfer_eo(head);
    add_collect(p->bs);

    uroutine u1 = {.consequence= p->rax, .status= p->status, .rid=p->rid};
    UROUTINE_NR[u1.rid] = u1;

    remove_from_routine_list(p->rid);

    free(transfer_eo(pop_head(&head, &tail)));
}

void exchange_c() {
    preuse e = NULL;
    while ((e = pop_head(&event_queue_h, &event_queue_r)) != NULL) {
        p_event pe = transfer_event(e);
        proutine v0 = transfer_eo(head);
        proutine v1 = transfer_eo(head);
        pe->even(&v0, &v1);
    }
    preuse h = pop_head(&head, &tail);
    insert_tail(&head, &tail, h);
    transfer_eo(get_top(&head, &tail))->status = R;
}

