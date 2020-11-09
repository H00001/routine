#ifndef __ROUTINE_H__
#define __ROUTINE_H__

#include <stdlib.h>
#include <stdarg.h>
#include "reuse.h"
#define STACK_LEN 1024
extern void exchange();
extern void stop_routine();
typedef void *any;

typedef unsigned long code_t;
typedef unsigned long data_t;
typedef unsigned long *data_p;
typedef unsigned long const *const_data_p;

typedef enum _STATUS
{
    R,
    Z,
    T,
    S,
    D,
    X,
    W
} STATUS;

typedef struct __u_routine
{
    const const_data_p conseqence;
    const STATUS* status;
} uroutine;

typedef struct __routine
{
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
    STATUS status;
    struct __routine *next;
} routine, *proutine;

typedef struct _collect
{
    reuse link;
    data_t length;
    data_p stack;
} collect, *pcollect;

void exchange_c(proutine *head, proutine *tail);
uroutine create_routine(any p);
void create_empty_routine();
void set_head_tail(proutine h, proutine t);
data_p acquire_stack0(int len);
void init_stack(data_p stack, int len, any p);
uroutine create_routine_with_params(any p, int num, ...);
#endif