//
// Created by dos DRTT on 11/13/20.
//
#include "routine_common.h"

preuse transfer_oe(proutine p) {
    return &p->u;
}

proutine transfer_eo(preuse p) {
    data_p k = (data_p) p;
    return (proutine) (k - 11);
}

p_event transfer_event(preuse p) {
    return (p_event) (p);
}

p_event create_event_1(rid_t rid, EvenFn even) {
    p_event e = malloc(sizeof(user_event));
    e->rid = rid;
    e->even = even;
    return e;
}

