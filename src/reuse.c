#include "reuse.h"

static int init(reuse_p *head, reuse_p *tail, reuse_p p) {
    if ((*head) == (*tail) && (*head) == NULL) {
        (*head) = p;
        (*tail) = p;
        p->prev = NULL;
        p->next = NULL;
        return 1;
    }
    return 0;
}

void insert_head(reuse_p *head, reuse_p *tail, reuse_p p) {
    if (init(head, tail, p)) {
        return;
    }
    reuse_p s = *head;
    *head = p;
    p->next = s;
    s->prev = p;
}

void insert_tail(reuse_p *head, reuse_p *tail, reuse_p p) {
    if (init(head, tail, p)) {
        return;
    }
    reuse_p s = *tail;
    *tail = p;
    p->prev = s;
    s->next = p;
}

reuse_p pop_head(reuse_p *head, reuse_p *tail) {
    if (*head == NULL) {
        return NULL;
    }
    reuse_p s = *head;
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

reuse_p detach(reuse_p *head, reuse_p *tail, reuse_p p) {
    if (*head == *tail) {
        (*head) = NULL;
        (*tail) = NULL;
        return p;
    }
    reuse_p pr = p->prev;
    reuse_p ne = p->next;
    if (pr == NULL && ne == NULL) {
        return NULL;
    }
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

reuse_p get_top(reuse_p *head) {
    return *head;
}

int foreach(reuse_p head, reuse_p tail, callback c) {
    if (tail == head && head == NULL) {
        return -1;
    }
    for (reuse_p move = head; move != NULL; move = move->next) {
        if (c(move) != 0) {
            break;
        }
    }
    return 0;
}