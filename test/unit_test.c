int test_eq(int v0, int v1) {
    if (v0 == v1) {
        printf("\033[92m[PASS]\033[0m %d\n", v0);
        return 0;
    }

    printf("\033[91m[FAIL]\033[0m %d not equal with %d\n", v0, v1);
    return -1;
}

int test_p_eq(void *v0, void *v1) {
    if (v0 == v1) {
        printf("\033[92m[PASS]\033[0m %p\n", v0);
        return 0;
    }

    printf("\033[91m[FAIL]\033[0m %p not equal with %p\n", v0, v1);
    return -1;
}
