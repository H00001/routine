//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_USER_API_H
#define ROUTINE_ROUTINE_USER_API_H

#include "routine_base.h"
#include <stdarg.h>

typedef struct u_routine {
    info i;
    data_t consequence;
} uroutine;

extern void exchange();

rid_t create_routine(any p);

rid_t create_routine_with_params(any p, int num, ...);

static unsigned int user_cond(rid_t rid, enum _EVENT e);

void insert_uroutine_map(info ii, data_t p);

static void execute_complete(info i, data_t r);

/**  user level 0 api **/

rid_t get_pid(rid_t);

rid_t get_rid();

unsigned int block(rid_t rid);

unsigned int resume(rid_t rid);

int wait_all();

STATUS get_status(rid_t rid);

data_t get_consequence(rid_t rid);

/**
 * wait routine, current routine will wait it's child routine
 * that specified executed complete.
 * @param id child routine id
 * @return wait times. times of executing function of `exchange`
 */
int wait_rt(rid_t id);

#endif //ROUTINE_ROUTINE_USER_API_H
