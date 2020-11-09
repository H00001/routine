#include "routine.h"
proutine head;
proutine tail;

pcollect coll;

data_p stack_from_collection()
{
    data_p s = coll->stack;
    coll = coll->link.next;
    return s;
}

data_p acquire_stack0(int len)
{
    return coll == NULL ? malloc(len * sizeof(data_t)) : stack_from_collection();
}

proutine create_routine0(any p)
{
    proutine r = malloc(sizeof(routine));
    r->stack = acquire_stack0(STACK_LEN);
    init_stack(r->stack, STACK_LEN, p);
    r->esp = (code_t)(r->stack + STACK_LEN - 2);
    r->ebp = (code_t)(r->stack + STACK_LEN - 1);
    r->status = W;
    tail->next = r;
    tail = r;
    return r;
}

uroutine create_routine_with_params(any p, int num, ...)
{
    proutine r = create_routine0(p);
    const uroutine u = {&(r->rax),&(r->status)};
    va_list valist;
    va_start(valist, num);
    data_p w = &(r->rdi);
    for (int i = 0; i < num; i++)
    {
       (*w) = va_arg(valist, int);
       w++;
    }
    va_end(valist);
    return u;
}

uroutine create_routine(any p)
{
    proutine r =create_routine0(p);
    const uroutine u = {&(r->rax),&(r->status)};
    return u;
}

void create_current_routine()
{
    proutine r = malloc(sizeof(routine));
    tail = head = r;
}
