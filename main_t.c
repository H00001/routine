#include <stdio.h>
#include "src/routine.h"

int add(int a, int b);
int routine_b(int k)
{
	for(int i = 0;i<k;i++){

		exchange();
		printf("i is :%d\n",i);
	}
	return 42;
}

int routine_add(int a, int b)
{
    int c = a + b;
    exchange();
    return c;
}

int main()
{
    create_current_routine();
    create_current_routine();
    uroutine e = create_routine_with_params(routine_add, 2, 3, 5);
    uroutine r = create_routine_with_params(routine_b, 1, 10);
    create_routine_with_params(routine_b, 1, 10);
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
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    printf("routineid:%d result:%lu,status:%d\n",r.rid, *(r.consequence), *(r.status));
    printf("routineid:%d result:%lu,status:%d\n",e.rid, *(e.consequence), *(e.status));
}
