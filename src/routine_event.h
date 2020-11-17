//
// Created by dos DRTT on 11/15/20.
//

#ifndef ROUTINE_ROUTINE_EVENT_H
#define ROUTINE_ROUTINE_EVENT_H

#include "routine_common.h"
#include "routine_base.h"

static reuse_p event_queue_h = NULL;
static reuse_p event_queue_r = NULL;

typedef struct _user_event {
    reuse_t u;
    EvenFn even;
    rid_t rid;
} user_event, *p_event;

p_event fetch_event();

p_event transfer_event(reuse_p p);

STATUS push_event(rid_t, STATUS s, STATUS n);

p_event create_event(rid_t rid, EvenFn even);

#endif //ROUTINE_ROUTINE_EVENT_H
