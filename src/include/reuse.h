#include "stdlib.h"

typedef struct _reuse {
    struct _reuse *prev;
    struct _reuse *next;
} reuse_t, *reuse_p;

typedef int(*callback)(reuse_p v);

void insert_head(reuse_p *head, reuse_p *tail, reuse_p p);

void insert_tail(reuse_p *head, reuse_p *tail, reuse_p p);

void insert_head_0(reuse_p reu, reuse_p p);

reuse_p pop_head(reuse_p *head, reuse_p *tail);

reuse_p detach(volatile reuse_p *head, volatile reuse_p *tail, reuse_p p);

reuse_p get_top(reuse_p *head);

int foreach(volatile reuse_p head, callback c);

reuse_p get(volatile reuse_p *head, volatile reuse_p *tail, callback c);

void insert_tail_0(reuse_p r, reuse_p p);

static int init_0(reuse_p r, reuse_p p);

reuse_p detach_0(reuse_p r, volatile reuse_p p);

reuse_p pop_head_0(reuse_p r);

int foreach_0(reuse_p head, callback c);

reuse_p get_top_0(reuse_p r);

reuse_p get_0(volatile reuse_p r, callback c);
