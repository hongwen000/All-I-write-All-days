#include <stdio.h>
void main() {
    int a[10];
    for(int i = 0; i < 10; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 11 - 1 - j; ++j) {
            if(a[j] > a[j + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < 10; ++i) {
        printf("%d\n", a[i]);
    }
}
