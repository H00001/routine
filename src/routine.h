#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include <stdarg.h>
#include<string.h>
#include "reuse.h"

#define STACK_LEN 1024



typedef void *any;

typedef unsigned long code_t;
typedef unsigned long data_t;
typedef unsigned long *data_p;
typedef unsigned long const *const_data_p;
typedef int rid_t;

typedef enum _STATUS {
    W = 0,
    Z,
    T = 2,
    S,
    D,
    X,
    R
} STATUS;

typedef struct __u_routine {
    const int rid;
    const const_data_p consequence;
    const STATUS *status;
} uroutine;

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
    data_p stack;
    struct {
        STATUS status;
        rid_t rid;
    };
    struct __routine *next;
} routine, *proutine;

typedef struct _collect {
    reuse link;
    data_t length;
    data_p stack;
} collect, *pcollect;

extern void exchange();
extern void stop_routine();

void exchange_c(proutine *head, proutine *tail);

uroutine create_routine(any p);

data_p acquire_stack0(int len);

void init_stack(proutine r,data_p stack, int len, any p);

uroutine create_routine_with_params(any p, int num, ...);

proutine create_current_routine();

void insert(proutine *n,proutine r);

void remove_from_bitmap(rid_t rid);

proutine init_routine();


#endif

