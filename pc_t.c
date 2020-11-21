//
// Created by dos DRTT on 11/20/20.
//

#include "./src/routine_user_api.h"
#include "stdio.h"

static int buff[100];
static int k = 0;

void product();

void consume();

int main() {
    create_routine(product);
    create_routine(consume);
    exchange();
    exchange();
    exchange();
    printf("main\n");
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    exchange();
    printf("main\n");
    exchange();
    exchange();
    exchange();
    printf("main\n");
    exchange();
    exchange();
    exchange();



}

void product() {
    printf("product\n");
    for (int i = 0; i < 100; ++i) {
        printf("product1\n");
        buff[k++] = rand();
        printf("produc2\n");
        exchange();
    }
}

void consume() {
    printf("consume\n");
    for (int i = 0; i < 100; ++i) {
        int v = buff[k--];
        printf("%d\n", v);
        exchange();
    }
}