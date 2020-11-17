include ./test/makefile
CC=gcc -std=gnu11
base=main_t.c src/routine_base.c src/stack_collect.c src/reuse.c src/routine_helper.c src/routine_user_api.c src/routine_dfa.c src/routine_common.c src/routine_event.c
freebsd: $(base) src/routine_freebsd.s
	$(CC) $^ -o $@ 

linux: $(base) src/routine_linux.s
	$(CC) $^ -o $@

check:
	make checker

distcheck:
	make checker

.PHONY:clean
clean:
	rm *.o freebsd linux
