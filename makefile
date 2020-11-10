CC=clang -std=gnu11 
base=main_test.c src/routine.c src/routine_helper.c src/reuse.c
freebsd: $(base) src/routine_freebsd.s
	$(CC) $^ -o $@ 

linux: $(base) src/routine_linux.s
	$(CC) $^ -o $@

check:
	
distcheck:

.PHONY:clean
clean:
	rm *.o freebsd linux
