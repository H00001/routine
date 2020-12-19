//
// Created by dos frank on 11/13/20.
//
#include "routine_common.h"


routine_p transfer_eo(reuse_p p) {
    data_p k = (data_p) p;
    return (routine_p) (k - sizeof(registers) / sizeof(data_t));
}

