//
// Created by dos DRTT on 11/12/20.
//

#ifndef ROUTINE_ROUTINE_COMMON_H
#define ROUTINE_ROUTINE_COMMON_H

#define STACK_LEN 1024
#define ROUTINE_SUM 0xFFFFFF

#include "bitmap.h"
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


typedef struct r_into {
    STATUS status;
    rid_t rid;
    rid_t pid;
} info;

typedef struct _base_stack {
    data_p stack;
    s_size_t size;
} base_stack;

typedef struct _registers {
    volatile code_t esp;
    volatile code_t ebp;
    data_t rdi;
    volatile data_t rsi;
    volatile data_t rdx;
    volatile data_t rcx;
    volatile data_t r8;
    volatile data_t r9;
    volatile data_t r10;
    volatile data_t rax;
    volatile data_t rbx;
    volatile data_t r11;
    volatile data_t r13;
    volatile data_t r14;
    volatile data_t r15;
} registers;


typedef void(*comp)(info i, data_t r);

typedef struct det {
    info inf;
    comp uf;
    tick_t tick;
} det;

typedef struct routine {
    registers r;
    reuse_t u;
    bitmap child;
    base_stack bs;
    det l;
} routine_t, *routine_p;


typedef struct queues {
    reuse_t r_queue;
    reuse_t ub_queue;
    reuse_t w_queue;
    reuse_t s_queue;
    reuse_t t_queue;
} routine_queues_t, *routine_queues_p;

typedef enum bool {
    true, false
} bool;

typedef void(*EvenFn)(routine_queues_p, routine_p curr);

routine_p transfer_eo(reuse_p p);


#endif //ROUTINE_ROUTINE_COMMON_H
