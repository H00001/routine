#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include <string.h>
#include "routine_common.h"
#include "routine_helper.h"
#include "stack_collect.h"
#include "routine_event.h"


extern void stop_routine();

static routine_p create_current_routine();

static void remove_from_routine_map(rid_t rid);

void remove_0();

void exchange_c();

routine_p has_routine(rid_t id);

rid_t create_sys_routine(any p, data_p dp, comp u);

reuse_p transfer_oe(routine_p p);

static void system_clean(rid_t id, rid_t pid, data_t p, STATUS s);

rid_t get_pid(rid_t rid);

rid_t get_curr_rid_();

rid_t get_once_child(rid_t id);

#endif

