//
// Created by dos DRTT on 11/15/20.
//

#ifndef ROUTINE_STACK_COLLECT_H
#define ROUTINE_STACK_COLLECT_H

#include "routine_common.h"

void release_routine(routine_p b);

routine_p acquire_routine(s_size_t len);

static void re_init(routine_p r);

#endif //ROUTINE_STACK_COLLECT_H
