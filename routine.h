//----------



typedef unsigned long   code_t;
typedef unsigned long   data_t;
typedef unsigned long*  data_p;


typedef struct __routine {
    code_t esp;
    code_t ebp;
    data_t rax;
    data_t rbx;
    data_t rcx;
    data_t rdx;
    struct __routine* next;
    data_p stack;
    data_t rsi;
    data_t rdi;
}routine,*proutine;


void exchange_c(proutine* head,proutine* tail);
