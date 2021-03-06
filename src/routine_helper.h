//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_HELPER_H
#define ROUTINE_ROUTINE_HELPER_H

#include "routine_common.h"
#include <stdlib.h>
#include <string.h>


void init_stack(routine_p r, any p, any stop);

routine_p init_routine(comp uf, routine_p p_routine, data_p params, s_size_t stack_len);

static rid_t set_rid(routine_p r);

static void set_init_params(data_p p, data_p params);

#endif //ROUTINE_ROUTINE_HELPER_H
