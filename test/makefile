checker:test_reuse.c ../src/reuse.c unit_test.c
	$(CC) $^ -o $@

bitmap:test_bitmap.c ../src/bitmap.c unit_test.c
	$(CC) $^ -o $@

pc:pc_t.c libroutine.a
	gcc-10 $< ../build/*.o -o $@ 


