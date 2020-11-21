#include "stdlib.h"

typedef struct _reuse {
    struct _reuse *prev;
    struct _reuse *next;
} reuse_t, *reuse_p;

typedef int(*callback)(reuse_p v);

void insert_head(reuse_p *head, reuse_p *tail, reuse_p p);

void insert_tail(reuse_p *head, reuse_p *tail, reuse_p p);

reuse_p pop_head(reuse_p *head, reuse_p *tail);

reuse_p detach(reuse_p *head, reuse_p *tail, reuse_p p);

reuse_p get_top(reuse_p *head);

int foreach(reuse_p head, reuse_p tail, callback c);