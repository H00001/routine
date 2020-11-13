#include "stdlib.h"

typedef struct _reuse {
    struct _reuse *prev;
    struct _reuse *next;
} reuse, *preuse;

void insert_head(preuse *head, preuse *tail, preuse p);

void insert_tail(preuse *head, preuse *tail, preuse p);

preuse pop_head(preuse *head, preuse *tail);

preuse detach(preuse *head, preuse *tail, preuse p);