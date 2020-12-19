#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include <string.h>
#include "routine_common.h"
#include "routine_helper.h"
#include "stack_collect.h"
#include "routine_event.h"
#include "routine_kernel_api.h"


extern void stop_routine();

static routine_p create_kernel_routine(comp u, routine_p p, data_p params);

static void system_clean(rid_t id, rid_t pid, data_t p, STATUS s);

void remove_0();

void sys_exchange();

rid_t create_sys_routine(any p, data_p params, comp u);

#endif

