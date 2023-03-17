//
// Created by dos DRTT on 11/15/20.
//

#include "./include/routine_event.h"

p_event transfer_event(reuse_p p) {
    return (p_event) (p);
}

p_event fetch_event() {
    return transfer_event(pop_head(&event_queue_h, &event_queue_r));
}

int ROUTINE_SLEEP(reuse_p r) {
    return transfer_eo(r)->l.tick-- != 0 ? 0 : -1;
}

void _ALL_TO_R(routine_queues_p q, routine_p curr) {
    curr->l.inf.status = R;
    insert_tail_0(&q->r_queue, &curr->u);
    detach_0(&q->r_queue, &curr->u);
}

void R_TO_UB(routine_queues_p q, routine_p curr) {
    detach_0(&q->r_queue, &curr->u);
    curr->l.inf.status = UB;
    insert_tail_0(&q->ub_queue, &curr->u);
}

void emp(routine_queues_p q, routine_p curr) {
}

STATUS push_event(rid_t id, STATUS s, STATUS n) {
    static EvenFn events[][8] = {
            {emp,       emp,       _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, R_TO_UB},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R},
            {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R}};

    insert_tail(&event_queue_h, &event_queue_r, &create_event(id, events[s][n])->u);
    return s;
}

p_event create_event(rid_t rid, EvenFn even) {
    p_event e = malloc(sizeof(user_event));
    e->rid = rid;
    e->even = even;
    return e;
}