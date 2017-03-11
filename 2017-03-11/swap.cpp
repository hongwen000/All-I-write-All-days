#include <iostream>
using std::cout;
using std::endl;
class WidgetImpl {
    public:
        WidgetImpl(int _a) : a(_a) { }
        int get() { return a;}
    private:
        int a;
};
class Widget {
    public:
        Widget() = delete;
        Widget(int _a) : pImpl(new WidgetImpl(_a)) { }
        Widget(const Widget& rhs) : pImpl(new WidgetImpl(*rhs.pImpl)) { }
        Widget& operator= (const Widget& rhs)
        {
            WidgetImpl* pImplOrig = pImpl;
            pImpl = new WidgetImpl(*rhs.pImpl);
            delete pImplOrig;
            return *this;
        }
        void swap(Widget& rhs)
        {
            using std::swap;
            swap(pImpl, rhs.pImpl);
        }
        int get() { return pImpl->get(); }
    private:
        WidgetImpl* pImpl;
};
namespace std {
    template<>
        void swap<Widget> (Widget &a, Widget &b)
        {
            cout << "specified" << endl;
            a.swap(b);
        }
}
int main()
{
    Widget obj1(10), obj2(20);
    using std::swap;
    swap(obj1, obj2);
    cout << obj1.get() << " " << obj2.get() << endl;
    return 0; 
}
