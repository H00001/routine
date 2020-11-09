#include "routine.h"
void remove(proutine *h,pcollect *c)
{
    pcollect t = malloc(sizeof(collect));
    t->stack = (*h)->stack;
    if((*c)!=NULL){
        t->link.next= (pcollect)(*c);
    }
    (*c) = t;

    (*h)->status = T;
    (*h)->stack = NULL;
    (*h) = (*h)->next;
}

void exchange_c(proutine *h, proutine *t)
{
    proutine n = (*h)->next;
    if (n == NULL)
    {
        return;
    }
    n->status = R;
    proutine curr = (*h);
    curr->next = NULL;
    (*t)->next = curr;
    (*t) = curr;
    (*h) = n;
}

void init_stack(data_p stack, int len, any p)
{
    stack[len - 1] = (code_t)stop_routine;
    stack[len - 2] = (code_t)p;
}
