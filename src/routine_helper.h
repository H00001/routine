//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_HELPER_H
#define ROUTINE_ROUTINE_HELPER_H

#include "routine_common.h"
#include <stdlib.h>
#include <string.h>


void init_stack(routine_p r, data_p stack, int len, any p, any stop);

routine_p init_routine(comp uf);

rid_t set_rid(routine_p r);

#endif //ROUTINE_ROUTINE_HELPER_H
