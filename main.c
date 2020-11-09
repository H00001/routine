#define STACK_LEN 1024
#include <stdlib.h>
#include <stdio.h>

#include "routine.h"

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

int main() {
    printf("hello\n");
    proutine e = create_routine((unsigned long) b,NULL);
    proutine r = create_routine((unsigned long) b,e);
    proutine f = create_empty_routine(r);
    set_head_tail(f,e);
    exchange();
    exchange();
    exchange();
    exchange();
    printf("4\n");
}
