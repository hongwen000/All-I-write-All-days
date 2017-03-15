struct S {
    static const int x;
};
const int f(const int& r)
{
    return 0;
}
int main()
{
    int n = 0 ? (1, S::x)
        : f(0);
    return 0;
}

