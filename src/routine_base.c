#include "./include/routine_base.h"

routine_queues_t s_queues;

rid_t create_sys_routine(any p, data_p params, comp u) {
    if (ul_get_routine(0) == NULL) {
        create_kernel_routine(system_clean, NULL, NULL, -1);
    }
    routine_p r = create_kernel_routine(u, transfer_eo(s_queues.r_queue.prev), params, STACK_LEN);
    init_stack(r, p, stop_routine);
    return r->l.inf.rid;
}


static routine_p create_kernel_routine(comp u, routine_p p, data_p params, s_size_t stack_len) {
    routine_p r = init_routine(u, p, params, stack_len);
    insert_tail_0(&s_queues.r_queue, &r->u);
    return ul_set_routine(r);
}

static void system_clean(info i, data_t p) {
}

void remove_0() {
    routine_p p = transfer_eo(pop_head_0(&s_queues.r_queue));

    // Execute user function,When it is complete.
    p->l.uf(p->l.inf, p->r.rax);

    ul_rm_routine(p->l.inf.rid);
    release_routine(p);

    foreach_0(s_queues.r_queue.prev, ROUTINE_SLEEP);
    for (p_event e = NULL; (e = fetch_event()) != NULL; e->even(&s_queues, ul_get_routine(e->rid)));

    ul_set_current_rid(transfer_eo(get_top_0(&s_queues.r_queue))->l.inf.rid);
}

void sys_exchange() {
    for (p_event e = NULL; (e = fetch_event()) != NULL;) {
        e->even(&s_queues, ul_get_routine(e->rid));
    }
    insert_tail_0(&s_queues.r_queue, pop_head_0(&s_queues.r_queue));
    routine_p r = transfer_eo(get_top_0(&s_queues.r_queue));
    r->l.inf.status = R;
    ul_set_current_rid(r->l.inf.rid);
}

    int find_child(reuse_p v) {
        return transfer_eo(v)->l.inf.pid == k_get_rid() ? 1 : 0;
    }
    
rid_t k_get_first_child(rid_t id) {
    if (id >= 1) {
        return ul_get_routine(id) == NULL ? -1 : id;
    }
    reuse_p rp;

    if ((rp = get_0(&s_queues.r_queue, find_child)) != NULL) {
        return transfer_eo(rp)->l.inf.rid;
    }
    return -1;
}

