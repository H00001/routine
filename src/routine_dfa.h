//
// Created by dos DRTT on 11/13/20.
//

#ifndef ROUTINE_ROUTINE_DFA_H
#define ROUTINE_ROUTINE_DFA_H

typedef enum _STATUS {
    W = 0,
    Z,
    T = 2,
    S,
    D,
    X,
    R,
    UB,
    UNDEFINED
} STATUS;

typedef enum _EVENT {
    USER_BLOCK,
    USER_CONTINUE
} EVENT;

typedef STATUS (*t)(EVENT);

STATUS status_tran(STATUS,EVENT);

 STATUS CUB_0(EVENT e);

static STATUS CT(EVENT e);

static STATUS CS(EVENT e);

static STATUS CD(EVENT e);

static STATUS CX(EVENT e);

static STATUS CW(EVENT e);

static STATUS CZ(EVENT e);

static STATUS CR(EVENT e);

#endif //ROUTINE_ROUTINE_DFA_H
