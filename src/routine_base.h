#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include<string.h>
#include "routine_common.h"
#include "routine_helper.h"
#include "stack_collect.h"
#include "routine_event.h"
#include "routine_user_api.h"


extern void stop_routine();

static routine_p create_current_routine();

static void remove_from_routine_map(rid_t rid);

void remove_0();

void exchange_c();

routine_p has_routine(rid_t id);

rid_t create_sys_routine(any p, data_p dp);

reuse_p transfer_oe(routine_p p);

routine_p transfer_eo(reuse_p p);

#endif

