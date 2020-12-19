#include <stdio.h>
#include "src/routine_user_api.h"

int add(int a, int b);

int routine_b(int k) {
    for (int i = 0; i < k; i++) {
        exchange();
        printf("i is :%d\n", i);

    }
    pid_t p = create_routine_with_params(routine_b, 2, 3, 5);
    printf("pid:%d,curr is %d\n", get_pid(p), get_rid());
    return 42;
}

int routine_add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    rid_t e = create_routine_with_params(routine_add, 2, 3, 5);
    rid_t r = create_routine_with_params(routine_b, 1, 10);
    pid_t k = create_routine_with_params(routine_b, 1, 10);
    for (int i = 0; i < 3; ++i) {
        create_routine_with_params(routine_b, 1, 10);
    }
    exchange();
    printf("hello\n");
    exchange();
    printf("hello\n");
    exchange();
    exchange();
    block(r);
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
    resume(r);
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
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    printf("routineid:%d result:%lu,status:%d,pid:%d\n", e, get_consequence(e), get_status(e), get_pid(e));
    printf("routineid:%d result:%lu,status:%d,pid:%d\n", r, get_consequence(r), get_status(r), get_pid(e));
}
