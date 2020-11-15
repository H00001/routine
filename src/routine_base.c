#include "routine_base.h"

preuse head;
preuse tail;
static preuse event_queue_h = NULL;
static preuse event_queue_r = NULL;
static preuse ub_head;
static preuse ub_tail;
static preuse colls;
static preuse colle;
proutine ROUTINE_NR[ROUTINE_SUM];
uroutine UROUTINE_NR[ROUTINE_SUM];


static data_p stack_from_collection() {
    pcollect pc = transfer_co(pop_head(&colls, &colle));
    data_p p = pc->bs.stack;
    free(pc);
    return p;
}

static data_p acquire_stack0(int len) {
    return colls == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection();
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
    insert_tail(&head, &tail, &r->u);
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
    proutine p = transfer_eo(head);
    t->bs = p->bs;

    insert_head(&colls, &colle, &t->link);

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

pcollect transfer_co(preuse p) {
    return (pcollect) (p);
}