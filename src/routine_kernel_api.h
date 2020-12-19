//
// Created by dos DRTT on 12/19/20.
//

#ifndef ROUTINE_ROUTINE_KERNEL_API_H
#define ROUTINE_ROUTINE_KERNEL_API_H

/** kernel 0 level api **/

const rid_t k_get_pid(rid_t rid);

const rid_t k_get_rid();

const rid_t k_get_first_child(rid_t id);

const bool k_has_routine(rid_t id);

const STATUS k_get_status(rid_t id);

const routine_p ul_set_routine(routine_p r);

const routine_p ul_get_routine(rid_t id);

/** kernel -1 level api **/

const routine_t h_get_routine(rid_t id);

void ul_rm_routine(rid_t id);

const bool h_update_status(rid_t id, STATUS status);

void ul_set_current_rid(rid_t id);

#endif //ROUTINE_ROUTINE_KERNEL_API_H