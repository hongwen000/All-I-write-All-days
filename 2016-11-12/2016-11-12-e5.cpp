#define f(a,b) a##b
#define g(a)   #a
#define h(a) g(a)
int main()
{
    h(1);
    h(f(1,2));
    g(f(1,2));
}
 
