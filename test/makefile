checker:test_reuse.c ../src/reuse.c unit_test.c
	$(CC) $^ -o $@

bitmap:test_bitmap.c ../src/bitmap.c unit_test.c
	$(CC) $^ -o $@

wait:test_wait.c unit_test.c
	gcc-10 $^ ../build/*.o -o $@

pc:pc_t.c unit_test.c
	gcc-10 $^ ../build/*.o -o $@

compare:compare.c unit_test.c
	gcc-10 $^ ../build/*.o -o $@


