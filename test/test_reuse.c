//
// Created by dos DRTT on 11/13/20.
//

#include <stdio.h>
#include "../src/reuse.h"
#include "unit_test.h"

typedef struct _v {
    reuse_t u;
    unsigned long k;
} v;

reuse_p head = NULL;
reuse_p tail = NULL;


void test_printf(reuse_p head) {
    reuse_p l = head;
    for (; l != NULL; l = l->next) {
        unsigned long *l1 = l;
        printf("value:%lu->", *(l1 + 2));
    }
    printf("\n");
}

void test_insert_head() {
    v *vv = malloc(sizeof(v));
    vv->k = 1;
    insert_head(&head, &tail, &vv->u);
    unsigned long *l1 = (unsigned long*) pop_head(&head, &tail);
    test_eq(*(l1 + 2), 1);
    test_p_eq(pop_head(&head, &tail), NULL);

}

int main() {
    test_insert_head();
    return 0;
}

