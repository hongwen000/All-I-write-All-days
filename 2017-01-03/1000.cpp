int PowerMod(int a, int b, int c)
{
    int ans = 1;
    while (b >= 1) {
        if (b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}
int Power(int a, int b)
{
    if (b == 0)
        return 1;
    int result = 1;
    while (b) {
        if (b & 1)
            result *= A;
        A *= A;
        n /= 2;
    }
    return result;
}
int PowerMod(int a, int b, int c)
{
    int ans = 1;
    a = a % c;
    while(b > 0) {
        if (b & 1)
            ans = (ans * a) % c;
        b /= 2;
        a = (a * a) % c;
    }
    return ans;
}
