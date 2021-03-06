#ifndef __ROUTINE_BASE_H__
#define __ROUTINE_BASE_H__

#include <stdlib.h>
#include <string.h>
#include "routine_common.h"
#include "routine_helper.h"
#include "stack_collect.h"
#include "routine_event.h"
#include "routine_kernel_api.h"


extern void stop_routine();

static routine_p create_kernel_routine(comp u, routine_p p, data_p params, s_size_t stack_len);

static void system_clean(info i, data_t p);

void remove_0();

void sys_exchange();

rid_t create_sys_routine(any p, data_p params, comp u);

#endif

