#include <iostream>
#include <string>
template<typename T>
class SquareMatrixBase {
    protected:
        void invert(std::size_t matrixSize)
        {
            std::cout << "runing Base invert" << std::endl;
        }
};

template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
    private:
        using SquareMatrixBase<T>::invert;
    public:
        void invert() { invert(n); }
};
int main()
{
    SquareMatrix<int, 10> obj;
    obj.invert();
    return 0;
}
