#include <stdio.h>

int main() {
    int num = 0;

    /*
     * n++;
     * __sync_fetch_and_add(10, 3) = 10
     * num = 13
     */
    printf("__sync_fetch_and_add(%d, %d) = %d\n", 0, 1, __sync_fetch_and_add(&num, 1));
    printf("num = %d\n", num);
}

