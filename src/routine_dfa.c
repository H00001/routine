//
// Created by dos DRTT on 11/13/20.
//

#include "routine_dfa.h"

static STATUS CW(EVENT e) {
    return W;
}

static STATUS CZ(EVENT e) {
    return Z;
}

STATUS CUB_0(EVENT e) {
    switch (e) {
        case USER_BLOCK:
            return UB;
        case USER_CONTINUE:
            return R;
        default:
            return UB;
    }
}

static STATUS CR(EVENT e) {
    switch (e) {
        case USER_BLOCK:
            return UB;
        case USER_CONTINUE:
            return R;
        default:
            return UB;
    }
}

static STATUS CT(EVENT e) {
    return T;
}

static STATUS CS(EVENT e) {
    return UNDEFINED;
}

static STATUS CD(EVENT e) {
    return UNDEFINED;
}

static STATUS CX(EVENT e) {
    return UNDEFINED;
}

STATUS status_tran(STATUS s, EVENT e) {
    static t STALiST[] = {CW, CZ, CT, CS, CD, CX, CR, CUB_0};
    return STALiST[s](e);
}