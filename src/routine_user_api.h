//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_USER_API_H
#define ROUTINE_ROUTINE_USER_API_H

#include "routine_event.h"
#include "routine_base.h"
#include <stdarg.h>

typedef struct __u_routine {
    rid_t rid;
    rid_t pid;
    data_t consequence;
    STATUS status;
} uroutine;

extern void exchange();

data_t get_consequence(rid_t rid);

rid_t create_routine(any p);

STATUS get_status(rid_t rid);

int block(rid_t rid);

int resume(rid_t rid);

rid_t create_routine_with_params(any p, int num, ...);

static int user_cond(rid_t rid, enum _EVENT e);

void insert_uroutine_map(rid_t id, rid_t pid, data_t p, STATUS s);

static void execute_complete();

rid_t get_prid(rid_t);

rid_t get_curr_rid();

int wait_all();

/**
 * wait routine, current routine will wait it's child routine
 * that specified executed complete.
 * @param id child routine id
 * @return wait times. times of executing function of `exchange`
 */
int wait_rt(rid_t id);

#endif //ROUTINE_ROUTINE_USER_API_H
