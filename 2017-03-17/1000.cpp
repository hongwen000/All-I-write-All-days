#pragma once
#include <cmath>
class MyPoint {
private:
    double x, y;

public:
    MyPoint()
        : x(0)
        , y(0){};
    MyPoint(double _x, double _y)
        : x(_x)
        , y(_y){};
    double getX() { return x; }
    double getY() { return y; }
    double distance(MyPoint& point)
    {
        return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
    }
};

