#include "reuse.h"

static int init(reuse_p *head, reuse_p *tail, reuse_p p) {
    if ((*head) == (*tail) && (*head) == NULL) {
        (*head) = (*tail) = p;
        p->prev = p->next = NULL;
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

void insert_head_0(reuse_p reu, reuse_p p) {
    insert_head(&reu->prev, &reu->next, p);
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
        *tail = *head = NULL;
        return s;
    }
    (*head) = s->next;
    s->next = (*head)->prev = NULL;
    return s;
}

reuse_p detach(volatile reuse_p *head, volatile reuse_p *tail, volatile reuse_p p) {
    if (*head == *tail) {
        (*head) = (*tail) = NULL;
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

int foreach(volatile reuse_p head, callback c) {
    for (reuse_p move = head; move != NULL; move = move->next) {
        if (c(move) != 0) {
            return 3;
        }
    }
    return 0;
}

reuse_p get(volatile reuse_p *head, volatile reuse_p *tail, callback c) {
    if (*tail == *head && *head == NULL) {
        return NULL;
    }
    for (reuse_p move = *head; move != NULL; move = move->next) {
        if (c(move) == 1) {
            return move;
        } else if (c(move) == 2) {
            return detach(head, tail, move);
        }
    }
    return NULL;
}