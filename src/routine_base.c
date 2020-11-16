#include "routine_base.h"

preuse head;
preuse tail;
static preuse ub_head;
static preuse ub_tail;
static proutine ROUTINE_NR[ROUTINE_SUM];

rid_t create_sys_routine(any p, data_p dt) {
    create_current_routine();
    proutine r = init_routine();
    ROUTINE_NR[set_rid(r)] = r;
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p, stop_routine);
    insert_tail(&head, &tail, &r->u);
    if (dt != NULL) {
        memcpy(&r->rdi, dt, 7 * sizeof(data_t));
    }
    return r->rid;
}

static proutine create_current_routine() {
    if (ROUTINE_NR[0] == NULL) {
        proutine p = init_routine();
        insert_head(&head, &tail, &p->u);
        ROUTINE_NR[0] = p;
    }
    return ROUTINE_NR[0];
}

static void remove_from_routine_map(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}

void remove_0() {
    proutine p = transfer_eo(head);
    add_collect(p->bs);

    insert_uroutine_map(p->rid, p->rax, p->status);
    remove_from_routine_map(p->rid);

    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&head, &tail, &ub_head, &ub_tail, ROUTINE_NR[e->rid]));

    free(transfer_eo(pop_head(&head, &tail)));
}

void exchange_c() {
    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&head, &tail, &ub_head, &ub_tail, ROUTINE_NR[e->rid]));
    insert_tail(&head, &tail, pop_head(&head, &tail));
    transfer_eo(get_top(&head, &tail))->status = R;
}

proutine has_routine(rid_t id) {
    return ROUTINE_NR[id];
}

preuse transfer_oe(proutine p) {
    return &p->u;
}

proutine transfer_eo(preuse p) {
    data_p k = (data_p) p;
    return (proutine) (k - 11);
}