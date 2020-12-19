
#include "../src/routine_user_api.h"
#include "unit_test.h"
#include <pthread.h>

#define SIZE  1000
static int buff[SIZE];
static int buff1[SIZE];
static int k = 0;
static int k1 = 0;
volatile static int p1;
int n = 50000;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void product();

void consume();

void product1();

void consume1();

int main(int argc, char **argv) {
    n = atoi(argv[1]);
    time_t t = time(NULL);
    for (int i = 0; i < n; ++i) {
        create_routine(product);
    }
    for (int i = 0; i < n; ++i) {
        create_routine(consume);
    }
    wait_all();

    time_t t1 = time(NULL);

    pthread_t *tc = malloc(sizeof(pthread_t));
    for (int i = 0; i < n * 2; i += 2) {
        pthread_create(tc + i, NULL, (void *) product1, NULL);
        pthread_create(tc + i + 1, NULL, (void *) consume1, NULL);
    }

    for (int i = 0; i < n * 2; i++) {
        pthread_join(tc[i], NULL);
    }

    time_t t2 = time(NULL);
    printf("n:%d,routine:%lu thread:%lu\n", n, t1 - t, t2 - t1);
}

void product() {
    for (int i = 0; i < SIZE; ++i) {
        buff[k++] = rand() % 100;
        p1 = buff[k - 1];
        exchange();
    }
}

void consume() {
    for (int i = 0; i < SIZE; ++i) {
        buff[--k];
        exchange();
    }
}


void product1() {
    for (int i = 0; i < SIZE; ++i) {
        pthread_mutex_lock(&mutex);
        if (k1 == SIZE - 1) {
            pthread_mutex_unlock(&mutex);
            return;
        }
        buff[k1++] = rand() % 100;
        pthread_mutex_unlock(&mutex);
    }
}

void consume1() {
    for (int i = 0; i < SIZE; ++i) {
        pthread_mutex_lock(&mutex);
        if (k1 == 0) {
            pthread_mutex_unlock(&mutex);
            return;
        }
        buff1[--k1];
        pthread_mutex_unlock(&mutex);
    }
}


