#include <stdio.h>
#include "../src/routine_user_api.h"

int add(int a, int b);

int routine_b(int k) {
    for (int i = 0; i < k; i++) {
        exchange();
        printf("i is :%d\n", i);
    }
    return 42;
}

int routine_add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    pid_t k = create_routine_with_params(routine_b, 1, 100);
    printf("rid:%d,pid:%d\n", k, get_prid(k));
    exchange();
    exchange();
    exchange();
    exchange();
    wait_all();
    printf("rid:%d,pid:%d\n", k, get_prid(k));
}
