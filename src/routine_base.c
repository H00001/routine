#include "routine_base.h"

static routine_p ROUTINE_NR[ROUTINE_SUM];
routine_queues_t s_queues;

rid_t create_sys_routine(any p, data_p params, comp u) {
    if (ROUTINE_NR[0] == NULL) {
        create_root_routine(system_clean, NULL, NULL);
    }
    routine_p r = create_root_routine(u, transfer_eo(s_queues.r_queue_s), params);
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p, stop_routine);
    return r->rid;
}


static routine_p create_root_routine(comp u, routine_p p, data_p params) {
    routine_p r = init_routine(u, p, params);
    insert_tail(&s_queues.r_queue_s, &s_queues.r_queue_e, &r->u);
    ROUTINE_NR[r->rid] = r;
    return r;
}

static void system_clean(rid_t id, rid_t pid, data_t p, STATUS s) {
}

static void remove_from_routine_map(rid_t rid) {
    ROUTINE_NR[rid] = NULL;
}

void remove_0() {
    routine_p p = transfer_eo(s_queues.r_queue_s);
    add_collect(p->bs);
    // Execute user function,When it is complete.
    p->uf(p->rid, p->pid, p->rax, p->status);

    remove_from_routine_map(p->rid);

    foreach(s_queues.s_queue_s, s_queues.r_queue_e, ROUTINE_SLEEP);
    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&s_queues, ROUTINE_NR[e->rid]));

    free(transfer_eo(pop_head(&s_queues.r_queue_s, &s_queues.r_queue_e)));
}

void sys_exchange() {
    for (p_event e = NULL; (e = fetch_event()) != NULL;) {
        e->even(&s_queues, ROUTINE_NR[e->rid]);
    }
    insert_tail(&s_queues.r_queue_s, &s_queues.r_queue_e, pop_head(&s_queues.r_queue_s, &s_queues.r_queue_e));
    transfer_eo(get_top(&s_queues.r_queue_s))->status = R;
}

routine_p has_routine(rid_t id) {
    return ROUTINE_NR[id];
}

reuse_p transfer_oe(routine_p p) {
    return &p->u;
}

rid_t get_pid(rid_t rid) {
    if (ROUTINE_NR[rid] == NULL) {
        return -1;
    }
    return ROUTINE_NR[rid]->pid;
}

rid_t get_curr_rid_() {
    return transfer_eo(s_queues.r_queue_s)->rid;
}


rid_t get_once_child(rid_t id) {
    if (id >= 1) {
        return ROUTINE_NR[id] == NULL ? -1 : id;
    }
    reuse_p rp;
    int find_child(reuse_p v) {
        return transfer_eo(v)->pid == get_curr_rid_() ? 1 : 0;
    }
    if ((rp = get(&s_queues.r_queue_s, &s_queues.r_queue_e, find_child)) != NULL) {
        return transfer_eo(rp)->rid;
    }
    return -1;
}