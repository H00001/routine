#include "routine_base.h"

static routine_p ROUTINE_NR[ROUTINE_SUM];
routine_queues_t s_queues;

rid_t create_sys_routine(any p, data_p dt) {
    create_current_routine();
    routine_p r = init_routine();
    ROUTINE_NR[set_rid(r)] = r;
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p, stop_routine);
    insert_tail(&s_queues.r_queue_s, &s_queues.r_queue_e, &r->u);
    if (dt != NULL) {
        memcpy(&r->rdi, dt, 7 * sizeof(data_t));
    }
    return r->rid;
}

static routine_p create_current_routine() {
    if (ROUTINE_NR[0] == NULL) {
        routine_p p = init_routine();
        insert_head(&s_queues.r_queue_s, &s_queues.r_queue_e, &p->u);
        ROUTINE_NR[0] = p;
    }
    return ROUTINE_NR[0];
}

static void remove_from_routine_map(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}

void remove_0() {
    routine_p p = transfer_eo(s_queues.r_queue_s);
    add_collect(p->bs);

    insert_uroutine_map(p->rid, p->rax, p->status);
    remove_from_routine_map(p->rid);

    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&s_queues, ROUTINE_NR[e->rid]));

    free(transfer_eo(pop_head(&s_queues.r_queue_s, &s_queues.r_queue_e)));
}

void exchange_c() {
    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&s_queues, ROUTINE_NR[e->rid]));
    insert_tail(&s_queues.r_queue_s, &s_queues.r_queue_e, pop_head(&s_queues.r_queue_s, &s_queues.r_queue_e));
    transfer_eo(get_top(&s_queues.r_queue_s))->status = R;
}

routine_p has_routine(rid_t id) {
    return ROUTINE_NR[id];
}

reuse_p transfer_oe(routine_p p) {
    return &p->u;
}

routine_p transfer_eo(reuse_p p) {
    data_p k = (data_p) p;
    return (routine_p) (k - 11);
}