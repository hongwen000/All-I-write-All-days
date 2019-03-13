#include <iostream>
#include <Eigen/Dense>
using namespace std;
class Foo
{
    public:
      Eigen::Vector2d v;
};
int main()
{
    Foo *foo = new Foo;
    cout << foo->v << endl;
}
