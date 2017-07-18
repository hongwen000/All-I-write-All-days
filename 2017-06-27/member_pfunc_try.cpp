#include <functional>
#include <iostream>
using namespace std;
struct test {
    int add(int i, int j) { return i + j; }
};

int main()
{
    test obj;

    typedef int (test::*pfunc_old_type)(int i, int j); //注意test::，这是和普通函数指针的区别
    pfunc_old_type pfunc_old = &test::add;

    auto pfunc = &test::add;

    function<int(int,int)> func_obj = bind(&test::add, obj, placeholders::_1, placeholders::_2); 

    auto func_obj_lambda = [&](auto i, auto j) { return (obj.add)(i, j); };

    cout << (obj.*pfunc_old)(1, 2) << endl;
    cout << (obj.*pfunc)(1, 2) << endl;
    cout << func_obj(1,2) << endl;
    cout << func_obj_lambda(1, 2) <<endl;
    cout << invoke(&test::add, 1, 2) << endl;
}


