//
// Created by dos DRTT on 11/13/20.
//

#include <stdio.h>
#include "../src/reuse.h"

typedef struct _v {
    reuse u;
    unsigned long k;
} v;

void test_printf(preuse head) {
    preuse l = head;
    for (; l != NULL; l = l->next) {
        unsigned long *l1 = l;
        printf("value:%lu->", *(l1 + 2));
    }
    printf("\n");
}

int main() {
    preuse head = NULL;
    preuse tail = NULL;
    v *vv = malloc(sizeof(v));
    vv->k = 1;
    v *vv1 = malloc(sizeof(v));
    vv1->k = 2;
    v *vv2 = malloc(sizeof(v));
    vv2->k = 5;
    v *vv5 = malloc(sizeof(v));
    vv5->k = 1;
    v *vv6 = malloc(sizeof(v));
    vv6->k = 2;
    v *vv7 = malloc(sizeof(v));
    vv7->k = 5;
    insert_head(&head, &tail, &(vv->u));
    insert_head(&head, &tail, &(vv1->u));
    insert_head(&head, &tail, &(vv2->u));
//    test_printf(head);
//    pop_head(&head,&tail);
//    test_printf(head);
//    pop_head(&head,&tail);
//    test_printf(head);
//    pop_head(&head,&tail);
detach(&head,&tail,&(vv1->u));
    test_printf(head);
    detach(&head,&tail,&(vv2->u));
    test_printf(head);
    detach(&head,&tail,&(vv->u));
    test_printf(head);
}

