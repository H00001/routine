#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include<string.h>
#include "reuse.h"
#include "routine_common.h"
#include "routine_helper.h"

typedef struct _collect {
    reuse link;
    base_stack bs;
} collect, *pcollect;

extern void exchange();

extern void stop_routine();

static data_p acquire_stack0(int len);

static proutine create_current_routine();

static void remove_from_routine_list(rid_t rid);

static data_p stack_from_collection();

void remove_0();

#endif

