//
// Created by dos DRTT on 11/13/20.
//
#include "routine_common.h"

preuse transfer_oe(proutine p) {
    return &p->u;
}

proutine transfer_eo(preuse p) {
    data_p k = (data_p) p;
    return (proutine) (k - 11);
}


