#include "./include/reuse.h"

static int init(reuse_p *head, reuse_p *tail, reuse_p p) {
    if ((*head) == (*tail) && (*head) == NULL) {
        (*head) = (*tail) = p;
        p->prev = p->next = NULL;
        return 1;
    }
    return 0;
}

static int init_0(reuse_p r, reuse_p p) {
    return init(&r->prev, &r->next, p);
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

void insert_head_0(reuse_p r, reuse_p p) {
    insert_head(&r->prev, &r->next, p);
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

void insert_tail_0(reuse_p r, reuse_p p) {
    insert_tail(&r->prev, &r->next, p);
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

reuse_p pop_head_0(reuse_p r) {
    return pop_head(&r->prev, &r->next);
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

reuse_p detach_0(reuse_p r, volatile reuse_p p) {
    return detach(&r->prev, &r->next, p);
}

reuse_p get_top(reuse_p *head) {
    return *head;
}

reuse_p get_top_0(reuse_p r) {
    return get_top(&r->prev);
}

int foreach(volatile reuse_p head, callback c) {
    for (reuse_p move = head; move != NULL; move = move->next) {
        if (c(move) != 0) {
            return 3;
        }
    }
    return 0;
}

int foreach_0(reuse_p head, callback c) {
    return foreach(head->prev, c);
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

reuse_p get_0(volatile reuse_p r, callback c) {
    return get(&r->prev, &r->next, c);
}
