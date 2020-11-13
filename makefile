CC=clang -std=gnu11 
base=main_t.c src/routine_base.c src/reuse.c src/routine_helper.c src/routine_user_api.c src/routine_dfa.c
freebsd: $(base) src/routine_freebsd.s
	$(CC) $^ -o $@ 

linux: $(base) src/routine_linux.s
	$(CC) $^ -o $@

check:./test/test_reuse.c ./src/reuse.c
	$(CC) $^ -o $@
distcheck:

.PHONY:clean
clean:
	rm *.o freebsd linux
