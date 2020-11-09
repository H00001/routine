CC=gcc
base=main.c routine.c routine.h
freebsd: $(base) routine_freebsd.s
	$(CC) $^ -o $@

linux: $(base) routine_linux.s
	$(CC) $^ -o $@

.PHONY:clean
clean:
	rm *.o freebsd linux
