#CC=gcc --std=gnu17
CC=gcc 
base=main.c routine.c reuse.c routine_helper.c
freebsd: $(base) routine_freebsd.s
	$(CC) $^ -o $@ 

linux: $(base) routine_linux.s
	$(CC) $^ -o $@

.PHONY:clean
clean:
	rm *.o freebsd linux
