//
// Created by dos DRTT on 11/12/20.
//

#include "routine_user_api.h"

static uroutine UROUTINE_NR[ROUTINE_SUM];

data_t get_consequence(rid_t rid) {
    return UROUTINE_NR[rid].consequence;
}

const STATUS get_status(rid_t rid) {
    return UROUTINE_NR[rid].status;
}

static int user_cond(rid_t rid, enum _EVENT e) {
    if (k_has_routine(rid) == false) {
        return -1;
    }
    routine_t p = h_get_routine(rid);
    int cur = p.status;
    int nxt = status_tran(p.status, e);
    return cur - nxt != 0 ? push_event(rid, cur, nxt) : 0;
}

const int block(rid_t rid) {
    return user_cond(rid, USER_BLOCK);
}

const int resume(rid_t rid) {
    return user_cond(rid, USER_CONTINUE);
}

const int sleep(rid_t rid) {
    return user_cond(rid, USER_CONTINUE);
}

rid_t create_routine(any p) {
    return create_sys_routine(p, NULL, execute_complete);
}

rid_t create_routine_with_params(any p, int num, ...) {
    data_p dp0 = malloc(6 * sizeof(data_t));
    data_p dp = dp0;
    va_list p_list;
    va_start(p_list, num);
    for (int i = 0; i < num; i++, dp++) {
        (*dp) = va_arg(p_list, data_t);
    }
    va_end(p_list);
    return create_sys_routine(p, dp0, execute_complete);
}

void insert_uroutine_map(rid_t id, rid_t pid, data_t r, STATUS s) {
    uroutine u1 = {.consequence= r, .status= s, .rid=id, .pid=pid};
    UROUTINE_NR[id] = u1;
}

static void execute_complete(rid_t id, rid_t pid, data_t r, STATUS s) {
    insert_uroutine_map(id, pid, r, s);
}

const rid_t get_pid(rid_t id) {
    return k_get_pid(id) < 0 ? UROUTINE_NR[id].pid : k_get_pid(id);
}

const rid_t get_rid() {
    return k_get_rid();
}

const int wait_all() {
    return wait_rt(-1);
}

const int wait_rt(const rid_t id) {
    int i = 0;
    for (; k_get_first_child(id) != -1; i++, exchange());
    return i;
}