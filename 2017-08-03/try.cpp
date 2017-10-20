#include <iostream>

class Point {
public:
    Point() = default;

    Point( int x, int y ) : x_{x}, y_{y} {}
    Point( int x ) : x_(x) {}

    // or in your case, you can use a default argument
    //Point( int x, int y = int{} ) : x_{x}, y_{y} {}

    int X() const { return x_; }
    int Y() const { return y_; }
private:
    int x_{};
    int y_{};
};

void DisplayPoint( Point const & p) {
    std::cout << "( " << p.X() << ", " << p.Y() << " )" << std::endl;
}

Point GetAPoint() {
    return { 3, 5 };
}

int main() {
    DisplayPoint( {} );
    DisplayPoint( { 1 } );
    DisplayPoint( { 1, 2 } );
    DisplayPoint( GetAPoint() );
    DisplayPoint( Point( 5, 3 ) ); // pre c++11
    DisplayPoint( Point{ 5, 3 } ); // in the case the constructor is explicit
}
