//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_COMMON_H
#define ROUTINE_ROUTINE_COMMON_H

#define STACK_LEN 1024
#define ROUTINE_SUM 0xFFFF

#include "stdlib.h"
#include "routine_dfa.h"
#include "reuse.h"

typedef void *any;

typedef unsigned long code_t;
typedef unsigned long data_t;
typedef unsigned long *data_p;
typedef unsigned long const *const_data_p;
typedef int rid_t;
typedef unsigned int s_size_t;

typedef struct __u_routine {
    rid_t rid;
    data_t consequence;
    STATUS status;
} uroutine;


typedef struct _base_stack {
    data_p stack;
    s_size_t size;
} base_stack;

typedef struct __routine {
    code_t esp;
    code_t ebp;
    data_t rdi;
    data_t rsi;
    data_t rdx;
    data_t rcx;
    data_t r8;
    data_t r9;
    data_t r10;
    data_t rax;
    data_t rbx;
    reuse u;
    base_stack bs;
    struct {
        STATUS status;
        rid_t rid;
    };
} routine, *proutine;

typedef void(*EvenFn)(proutine *head, proutine *tail);

typedef struct _user_event {
    reuse u;
    EvenFn even;
    rid_t rid;
} user_event,*p_event;

preuse transfer_oe(proutine p);

proutine transfer_eo(preuse p);

p_event transfer_event(preuse p);

p_event create_event_1(rid_t rid,EvenFn even);


#endif //ROUTINE_ROUTINE_COMMON_H
