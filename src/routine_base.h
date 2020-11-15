#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include<string.h>
#include "routine_common.h"
#include "routine_helper.h"
#include "stack_collect.h"

extern void exchange();

extern void stop_routine();

static proutine create_current_routine();

static void remove_from_routine_list(rid_t rid);

void remove_0();

void exchange_c();


#endif

