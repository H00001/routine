CC=gcc
freebsd: main.c routine_freebsd.s routine.h
	$(CC) main.c routine_freebsd.s -o freebsd

linux: main.c routine_linux.s routine.h
	$(CC) main.c routine_linux.s -o linux

clean:
	rm *.o freebsd linux
