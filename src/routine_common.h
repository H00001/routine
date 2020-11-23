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
typedef unsigned int tick_t;

typedef void(*comp)(rid_t id, data_t r, STATUS s);


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
    reuse_t u;
    base_stack bs;
    struct {
        STATUS status;
        rid_t rid;
    };
    comp uf;
    tick_t tick;
} routine_t, *routine_p;

typedef struct _queues {
    struct {
        reuse_t *r_queue_s;
        reuse_t *r_queue_e;
    };
    struct {
        reuse_t *ub_queue_s;
        reuse_t *ub_queue_e;
    };
    struct {
        reuse_t *w_queue_s;
        reuse_t *w_queue_e;
    };
    struct {
        reuse_t *s_queue_s;
        reuse_t *s_queue_e;
    };
    struct {
        reuse_t *t_queue_s;
        reuse_t *t_queue_e;
    };
} routine_queues_t, *routine_queues_p;

typedef enum _bool {
    true, false
} bool;

typedef void(*EvenFn)(routine_queues_p, routine_p curr);

int func_common();


#endif //ROUTINE_ROUTINE_COMMON_H
