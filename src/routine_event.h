//
// Created by dos DRTT on 11/15/20.
//

#ifndef ROUTINE_ROUTINE_EVENT_H
#define ROUTINE_ROUTINE_EVENT_H
#include "routine_common.h"

static preuse event_queue_h = NULL;
static preuse event_queue_r = NULL;

typedef struct _user_event {
    reuse u;
    EvenFn even;
    rid_t rid;
} user_event, *p_event;

p_event fetch_event();

p_event transfer_event(preuse p);

STATUS push_event(rid_t, STATUS s, STATUS n);

p_event create_event(rid_t rid, EvenFn even);

#endif //ROUTINE_ROUTINE_EVENT_H
