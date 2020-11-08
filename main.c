#define STACK_LEN 1024
#include <stdlib.h>
#include <stdio.h>

#include "routine.h"

typedef void* any;

proutine head;
proutine tail;

extern void exchange();

void exchange_c(proutine* h,proutine* t){
    proutine curr = head;
    proutine n = head->next;
    curr->next = NULL;
    tail->next = curr;
    tail = curr;
    head = n;
}

int b() {
    int i = 0;
    printf("i am function of b, you are succeed\n");
    exchange();
    printf("i am function of c, you are succeed\n");
    i++;
    exchange();
    printf("i am function of d, you are succeed\n");
    i++;
    printf("%d\n",i);
    exchange();
    printf("i am function of e, you are succeed\n");
    exchange();
    return 0;
}

proutine create_routine(any p,proutine next) {
    proutine r = malloc(sizeof(routine));
    r->stack = malloc(STACK_LEN*sizeof(data_t));
    r->stack[STACK_LEN - 1] = (code_t) b;
    r->esp = (code_t) (r->stack + STACK_LEN - 1);
    r->ebp = (code_t) (r->stack + STACK_LEN);
    r->next = next;
    return r;
}

proutine create_empty_routine(proutine next) {
    proutine r = malloc(sizeof(routine));
    r->next = next;
    return r;
}

int main() {
//    printf("hello\n");
    proutine e = create_routine((unsigned long) b,NULL);
    proutine r = create_routine((unsigned long) b,e);
    proutine f = create_empty_routine(r);
    head = f;
    tail = e;
    exchange();
    exchange();
    exchange();
    exchange();
    printf("4\n");
}
