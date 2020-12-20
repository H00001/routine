#include "routine_base.h"

routine_queues_t s_queues;

rid_t create_sys_routine(any p, data_p params, comp u) {
    if (ul_get_routine(0) == NULL) {
        create_kernel_routine(system_clean, NULL, NULL);
    }
    routine_p r = create_kernel_routine(u, transfer_eo(s_queues.r_queue_s), params);
    init_stack(r, acquire_stack0(STACK_LEN), STACK_LEN, p, stop_routine);
    return r->rid;
}


static routine_p create_kernel_routine(comp u, routine_p p, data_p params) {
    routine_p r = init_routine(u, p, params);
    insert_tail(&s_queues.r_queue_s, &s_queues.r_queue_e, &r->u);
    return ul_set_routine(r);
}

static void system_clean(rid_t id, rid_t pid, data_t p, STATUS s) {
}

void remove_0() {
    routine_p p = transfer_eo(pop_head(&s_queues.r_queue_s, &s_queues.r_queue_e));
    release_routine(p);
    // Execute user function,When it is complete.
    p->uf(p->rid, p->pid, p->r.rax, p->status);

    ul_rm_routine(p->rid);

    foreach(s_queues.s_queue_s, ROUTINE_SLEEP);
    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&s_queues, ul_get_routine(e->rid)));

    ul_set_current_rid(transfer_eo(get_top(&s_queues.r_queue_s))->rid);
}

void sys_exchange() {
    for (p_event e = NULL; (e = fetch_event()) != NULL;) {
        e->even(&s_queues, ul_get_routine(e->rid));
    }
    insert_tail(&s_queues.r_queue_s, &s_queues.r_queue_e, pop_head(&s_queues.r_queue_s, &s_queues.r_queue_e));
    routine_p r = transfer_eo(get_top(&s_queues.r_queue_s));
    r->status = R;
    ul_set_current_rid(r->rid);
}

rid_t k_get_first_child(rid_t id) {
    if (id >= 1) {
        return ul_get_routine(id) == NULL ? -1 : id;
    }
    reuse_p rp;
    int find_child(reuse_p v) {
        return transfer_eo(v)->pid == k_get_rid() ? 1 : 0;
    }
    if ((rp = get(&s_queues.r_queue_s, &s_queues.r_queue_e, find_child)) != NULL) {
        return transfer_eo(rp)->rid;
    }
    return -1;
}

