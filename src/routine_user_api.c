//
// Created by dos DRTT on 11/12/20.
//

#include "routine_user_api.h"

static uroutine UROUTINE_NR[ROUTINE_SUM];

data_t get_consequence(rid_t rid) {
    return UROUTINE_NR[rid].consequence;
}

STATUS get_status(rid_t rid) {
    return UROUTINE_NR[rid].status;
}

static int user_cond(rid_t rid, enum _EVENT e) {
    proutine p;
    if ((p = has_routine(rid)) == NULL) {
        return false;
    }

    int cur = p->status;
    int nxt = status_tran(p->status, e);
    return push_event(rid, cur, nxt);
}

int block(rid_t rid) {
    return user_cond(rid, USER_BLOCK);
}

int resume(rid_t rid) {
    return user_cond(rid, USER_CONTINUE);
}

rid_t create_routine(any p) {
    return create_sys_routine(p, NULL);
}

rid_t create_routine_with_params(any p, int num, ...) {
    data_p dp0 = malloc(7 * sizeof(data_t));
    data_p dp = dp0;
    va_list p_list;
    va_start(p_list, num);
    for (int i = 0; i < num; i++, dp++) {
        (*dp) = va_arg(p_list, data_t);
    }
    va_end(p_list);
    return create_sys_routine(p, dp0);
}

void insert_uroutine_map(rid_t id, data_t r, STATUS s) {
    uroutine u1 = {.consequence= r, .status= s, .rid=id};
    UROUTINE_NR[id] = u1;
}
