struct A{};
A getA()
{
    return A();
}
int main()
{
    A&& a = getA();
}
