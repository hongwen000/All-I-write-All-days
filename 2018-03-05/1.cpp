template <typename T>
class A{
    T data1;
};
template <>
class A<int>{
    int data1;
    double data2;
};
