//
// Created by dos DRTT on 11/12/20.
//

#include "routine_user_api.h"

extern proutine ROUTINE_NR[ROUTINE_SUM];
extern uroutine *UROUTINE_NR[ROUTINE_SUM];

data_t get_consequence(rid_t rid) {
    return UROUTINE_NR[rid]->consequence;
}

STATUS get_status(rid_t rid) {
    return UROUTINE_NR[rid]->status;
}

int block(rid_t rid){
    if (ROUTINE_NR[rid]==NULL){
        return -1;
    }
    return ROUTINE_NR[rid]->status = UB;
}

int resume(rid_t rid){
    if (ROUTINE_NR[rid]==NULL){
        return -1;
    }
    return ROUTINE_NR[rid]->status = R;
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