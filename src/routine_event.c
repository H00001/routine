//
// Created by dos DRTT on 11/15/20.
//

#include "routine_event.h"

p_event transfer_event(preuse p) {
    return (p_event) (p);
}

p_event fetch_event() {
    return transfer_event(pop_head(&event_queue_h, &event_queue_r));
}

void _ALL_TO_R(routine_queues_p q, proutine curr) {
    // ?
    curr->status = R;
    insert_tail(&q->r_queue_s, &q->r_queue_e, &curr->u);
    detach(&q->ub_queue_s, &q->ub_queue_e, &curr->u);
}

void R_TO_UB(routine_queues_p q, proutine curr) {
    detach(&q->r_queue_s, &q->r_queue_e, &curr->u);
    // insert to uB queue
    // detach fail ?

    curr->status = UB;
    insert_tail(&q->ub_queue_s, &q->ub_queue_e, &curr->u);
}

void emp(routine_queues_p q, proutine curr) {
}

STATUS push_event(rid_t id, STATUS s, STATUS n) {
    printf("cuuu:%d,%d", s, n);
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