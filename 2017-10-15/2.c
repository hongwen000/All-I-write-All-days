int f(int*);
int main() {
    int a[64];
    f(a);
}
int f(int* a) {
    return a[0];
}
