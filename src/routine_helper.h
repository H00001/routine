//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_HELPER_H
#define ROUTINE_ROUTINE_HELPER_H

#include "routine_common.h"
#include <stdlib.h>
#include <string.h>

void init_stack(proutine r, data_p stack, int len, any p, any stop);

proutine init_routine();

#endif //ROUTINE_ROUTINE_HELPER_H
