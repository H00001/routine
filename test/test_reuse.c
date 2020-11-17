//
// Created by dos DRTT on 11/13/20.
//

#include <stdio.h>
#include "../src/reuse.h"
#include "unit_test.h"

typedef struct _v {
    reuse u;
    unsigned long k;
} v;

preuse head = NULL;
preuse tail = NULL;


void test_printf(preuse head) {
    preuse l = head;
    for (; l != NULL; l = l->next) {
        unsigned long *l1 = l;
        printf("value:%lu->", *(l1 + 2));
    }
    printf("\n");
}

int test_insert_head() {
    v *vv = malloc(sizeof(v));
    vv->k = 1;
    insert_head(&head, &tail, &vv->u);
    unsigned long *l1 = pop_head(&head, &tail);
    test_eq(*(l1 + 2), 1);
}

int main() {
    test_insert_head();
    return 0;
}

