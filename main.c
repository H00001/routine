#include <stdio.h>
#include "routine.h"


int add(int a,int b);
int b(int k) {
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
	printf("tk:%d\n",add(100,200));
    exchange();
    return k;
}

int add(int a,int b){
	printf("add\n");
	int c = a+b;
	exchange();
	return c;
}

int main() {
    create_current_routine();
    uroutine e = create_routine(b);
    uroutine r = create_routine_with_params(b,1,10);
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
        printf("result:%d,starus:%d",*(r.conseqence),*(r.status));

    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    printf("result:%d,starus:%d",*(r.conseqence),*(r.status));
}
