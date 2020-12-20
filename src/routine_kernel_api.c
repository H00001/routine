#include "routine_base.h"

static routine_p ROUTINE_NR[ROUTINE_SUM];
static rid_t current_rid = 0;

const bool k_has_routine(rid_t id) {
    return ROUTINE_NR[id] != NULL ? true : false;
}

rid_t k_get_pid(rid_t rid) {
    return ROUTINE_NR[rid] == NULL ? -1 : ROUTINE_NR[rid]->l.inf.pid;
}

rid_t k_get_rid() {
    return current_rid;
}

STATUS k_get_status(rid_t id) {
    return ROUTINE_NR[id]->l.inf.status;
}

routine_t h_get_routine(rid_t id) {
    return *ROUTINE_NR[id];
}

bool h_update_status(rid_t id, STATUS status) {
    ROUTINE_NR[id]->l.inf.status = status;
    return true;
}

routine_p ul_set_routine(routine_p r) {
    return ROUTINE_NR[r->l.inf.rid] = r;
}

routine_p ul_get_routine(rid_t id) {
    return ROUTINE_NR[id];
}

void ul_rm_routine(rid_t id) {
    ROUTINE_NR[id] = NULL;
}

void ul_set_current_rid(rid_t id) {
    current_rid = id;
}