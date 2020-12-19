//
// Created by dos DRTT on 11/20/20.
//

#include "../src/routine_user_api.h"
#include "unit_test.h"


static int buff[100];
static int k = 0;

volatile static int p1;

void product();

void consume();

int main() {
    create_routine(product);
    create_routine(product);
    create_routine(product);
    create_routine(product);
    create_routine(consume);
    create_routine(consume);
    create_routine(consume);
    create_routine(consume);
    wait_all();
}

void product() {
    printf("product running\n");
    for (int i = 0; i < 100; ++i) {
        buff[k++] = rand() % 100;
        printf("product:%d\n", buff[k - 1]);
        p1 = buff[k - 1];
        exchange();
    }
}

void consume() {
    printf("consume running\n");
    for (int i = 0; i < 100; ++i) {
        int v = buff[--k];
        printf("consume:%d\n", v);
        test_eq(v, p1);
        exchange();
    }
}