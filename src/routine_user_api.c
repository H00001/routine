//
// Created by dos DRTT on 11/12/20.
//

#include "routine_user_api.h"

extern proutine ROUTINE_NR[ROUTINE_SUM];
extern uroutine UROUTINE_NR[ROUTINE_SUM];

data_t get_consequence(rid_t rid) {
    return UROUTINE_NR[rid].consequence;
}

STATUS get_status(rid_t rid) {
    return UROUTINE_NR[rid].status;
}

static int user_cond(rid_t rid, enum _EVENT e) {
    if (ROUTINE_NR[rid] == NULL) {
        return -1;
    }
    int cur = ROUTINE_NR[rid]->status;
    int nxt = status_tran(ROUTINE_NR[rid]->status, e);
    return create_event(rid, cur, nxt);
}

int block(rid_t rid) {
    return user_cond(rid, USER_BLOCK);
}

int resume(rid_t rid) {
    return user_cond(rid, USER_CONTINUE);
}

rid_t create_routine(any p) {
    return create_routine0(p)->rid;
}

rid_t create_routine_with_params(any p, int num, ...) {
    proutine r = create_routine0(p);
    va_list p_list;
    va_start(p_list, num);
    data_p w = &(r->rdi);
    for (int i = 0; i < num; i++, w++) {
        (*w) = va_arg(p_list, data_t);
    }
    va_end(p_list);
    return r->rid;
}

void _ALL_TO_R(proutine *head, proutine *tail) {

}

STATUS create_event(rid_t id, STATUS s, STATUS n) {
    p_event e = create_event_1(id, _ALL_TO_R);
    insert_tail(&event_queue_h, &event_queue_r, &e->u);
    return s;
}