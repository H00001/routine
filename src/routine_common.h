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

typedef struct _queues {
    struct {
        reuse *r_queue_s;
        reuse *r_queue_e;
    };
    struct {
        reuse *ub_queue_s;
        reuse *ub_queue_e;
    };
    struct {
        reuse *w_queue_s;
        reuse *w_queue_e;
    };
    struct {
        reuse *s_queue_s;
        reuse *s_queue_e;
    };
    struct {
        reuse *t_queue_s;
        reuse *t_queue_e;
    };
} routine_queues_t, *routine_queues_p;

typedef enum _bool {
    true, false
} bool;

typedef void(*EvenFn)(routine_queues_p, proutine curr);


#endif //ROUTINE_ROUTINE_COMMON_H
