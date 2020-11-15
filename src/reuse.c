#include "reuse.h"

static int init(preuse *head, preuse *tail, preuse p) {
    if ((*head) == (*tail) && (*head) == NULL) {
        (*head) = p;
        (*tail) = p;
        p->prev = NULL;
        p->next = NULL;
        return 1;
    }
    return 0;
}

void insert_head(preuse *head, preuse *tail, preuse p) {
    if (init(head, tail, p)) {
        return;
    }
    preuse s = *head;
    *head = p;
    p->next = s;
    s->prev = p;
}

void insert_tail(preuse *head, preuse *tail, preuse p) {
    if (init(head, tail, p)) {
        return;
    }
    preuse s = *tail;
    *tail = p;
    p->prev = s;
    s->next = p;
}

preuse pop_head(preuse *head, preuse *tail) {
    if (*head == NULL) {
        return NULL;
    }
    preuse s = *head;
    if (*head == *tail) {
        *tail = NULL;
        *head = NULL;
        return s;
    }
    (*head) = s->next;
    (*head)->prev = NULL;
    s->next = NULL;
    return s;
}

preuse detach(preuse *head, preuse *tail, preuse p) {
    if (*head == *tail) {
        (*head) = NULL;
        (*tail) = NULL;
        return p;
    }
    preuse pr = p->prev;
    preuse ne = p->next;
    if (pr == NULL) {
        (*head) = ne;
        ne->prev = NULL;
    } else {
        pr->next = ne;
    }
    if (ne == NULL) {
        (*tail) = pr;
        pr->next = NULL;
    } else {
        ne->prev = pr;
    }
    return p;
}

preuse get_top(preuse *head, preuse *tail){
    return *head;
}