CC=clang -std=gnu11 
base=main_t.c src/routine.c src/reuse.c src/routine_helper.c
freebsd: $(base) src/routine_freebsd.s
	$(CC) $^ -o $@ 

linux: $(base) src/routine_linux.s
	$(CC) $^ -o $@

.PHONY:clean
clean:
	rm *.o freebsd linux
