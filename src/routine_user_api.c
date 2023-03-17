//
// Created by dos DRTT on 11/12/20.
//

#include "./include/routine_user_api.h"

static uroutine UROUTINE_NR[ROUTINE_SUM];

data_t get_consequence(rid_t rid) {
    return UROUTINE_NR[rid].consequence;
}

STATUS get_status(rid_t rid) {
    return UROUTINE_NR[rid].i.status;
}

static unsigned int user_cond(rid_t rid, enum _EVENT e) {
    if (k_has_routine(rid) == false) {
        return -1;
    }
    routine_t p = h_get_routine(rid);
    int cur = p.l.inf.status;
    int nxt = status_tran(p.l.inf.status, e);
    return cur - nxt != 0 ? push_event(rid, cur, nxt) : 0;
}

unsigned int block(rid_t rid) {
    return user_cond(rid, USER_BLOCK);
}

unsigned int resume(rid_t rid) {
    return user_cond(rid, USER_CONTINUE);
}

unsigned int sleep(rid_t rid) {
    return user_cond(rid, USER_CONTINUE);
}

rid_t create_routine(any p) {
    return create_sys_routine(p, NULL, execute_complete);
}

/**
 * @brief Create a routine with params object
 * 
 * @param p function address
 * @param params_sum the sum of params 
 * @param ... variable parameters
 * @return rid_t routine id
 */
rid_t create_routine_with_params(any p, int params_sum, ...) {
    data_p dp0 = malloc(6 * sizeof(data_t));
    data_p dp = dp0;
    va_list p_list;
    va_start(p_list, params_sum);
    for (int i = 0; i < params_sum; i++, dp++) {
        (*dp) = va_arg(p_list, data_t);
    }
    va_end(p_list);
    return create_sys_routine(p, dp0, execute_complete);
}

void insert_uroutine_map(info i, data_t res) {
    uroutine u1 = {.i= i, .consequence=res};
    UROUTINE_NR[i.rid] = u1;
}

static void execute_complete(info i, data_t r) {
    insert_uroutine_map(i, r);
}

rid_t get_pid(rid_t id) {
    return k_get_pid(id) < 0 ? UROUTINE_NR[id].i.pid : k_get_pid(id);
}

rid_t get_rid() {
    return k_get_rid();
}

int wait_all() {
    return wait_rt(-1);
}

int wait_rt(const rid_t id) {
    int i = 0;
    for (; k_get_first_child(id) != -1; i++, exchange());
    return i;
}