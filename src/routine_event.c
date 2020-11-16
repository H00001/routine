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

void _ALL_TO_R(preuse *head, preuse *tail, preuse *ub_sta, preuse *ub_end, proutine curr) {
    curr->status = R;
    insert_head(head, tail, &curr->u);
    detach(ub_sta,ub_end, &curr->u);
}

void R_TO_UB(preuse *head, preuse *tail, preuse *ub_sta, preuse *ub_end,  proutine curr) {
    detach(head, tail, &curr->u);
    // insert to uB queue
    curr->status=UB;
    insert_head(ub_sta, ub_end, &curr->u);
}

STATUS push_event(rid_t id, STATUS s, STATUS n) {
    static EvenFn events[] = {_ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R,
                              _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R,
                              _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R, _ALL_TO_R};
    insert_tail(&event_queue_h, &event_queue_r, &create_event(id, events[s | n])->u);
    return s;
}

p_event create_event(rid_t rid, EvenFn even) {
    p_event e = malloc(sizeof(user_event));
    e->rid = rid;
    e->even = even;
    return e;
}