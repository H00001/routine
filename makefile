#CC=gcc --std=gnu17
CC=clang -std=c11 
base=main.c routine.c reuse.c routine_helper.c
freebsd: $(base) routine_freebsd.s
	$(CC) $^ -o $@ 

linux: $(base) routine_linux.s
	$(CC) $^ -o $@

.PHONY:clean
clean:
	rm *.o freebsd linux
