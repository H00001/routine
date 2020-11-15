//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_USER_API_H
#define ROUTINE_ROUTINE_USER_API_H

#include "routine_common.h"
#include <stdarg.h>

static preuse event_queue_h;
static preuse event_queue_r;

extern proutine create_routine0(any p);

data_t get_consequence(rid_t rid);

rid_t create_routine(any p);

STATUS get_status(rid_t rid);

int block(rid_t rid);

int resume(rid_t rid);

extern void exchange();

rid_t create_routine_with_params(any p, int num, ...);

STATUS create_event(rid_t, STATUS s, STATUS n);

void _ALL_TO_R();

static int user_cond(rid_t rid, enum _EVENT e);

#endif //ROUTINE_ROUTINE_USER_API_H
