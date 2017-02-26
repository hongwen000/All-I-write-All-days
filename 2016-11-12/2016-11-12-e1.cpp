int (*pf)(void);
int f(void)
{

       pf = &f; // 没问题
          pf = ***f; // 取址？
//             pf(); // 函数指针可以调用？
                (****pf)();  // 这又是什么？
                   (***************f)(); // 这个够变态了吧？
}
long factorial(int n){
        long result;
            if(n==0 || n==1){
                        result = 1;
                            }else{
                                        result = factorial(n-1) * n;  // 递归调用
                                            }
                return result;
}
int main()
{
 //   f();
 factorial(10);
    return 0;
}
