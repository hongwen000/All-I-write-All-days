int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
bool prime(int n)
{
    for (int i = 2; i <= sqrt(n))
        if (n % i == 0) return false;
    return true;
}
