#include<stdio.h>
int test_eq(int v0,int v1){
    if(v0==v1){
        printf("\033[92m[PASS]\033[0m %d\n",v0);
	return 0;
    }
	
   printf("\033[91m[FAIL]\033[0m %d:%d\n",v0,v1);
    return 0;
}
