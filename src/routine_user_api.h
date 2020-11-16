//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_USER_API_H
#define ROUTINE_ROUTINE_USER_API_H

#include "routine_common.h"
#include "routine_event.h"
#include "routine_base.h"
#include <stdarg.h>

extern proutine create_routine0(any p);

data_t get_consequence(rid_t rid);

rid_t create_routine(any p);

STATUS get_status(rid_t rid);

int block(rid_t rid);

int resume(rid_t rid);

extern void exchange();

rid_t create_routine_with_params(any p, int num, ...);

void _ALL_TO_R();

static int user_cond(rid_t rid, enum _EVENT e);

void insert_uroutine_map(rid_t id, data_t p,STATUS s);

#endif //ROUTINE_ROUTINE_USER_API_H
