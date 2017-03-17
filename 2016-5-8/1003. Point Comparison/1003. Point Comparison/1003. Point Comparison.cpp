// 1003. Point Comparison.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//(A.x<B.x) or (A.x == B.x & A.y<B.y) .

class Point
{
public:
	Point(int x1 = 0, int y1 = 0) { x = x1, y = y1; }
	friend bool operator < (const Point p1, const Point p2);
private:
	int x, y;
};

int main()
{
    return 0;
}

bool operator<(const Point p1, const Point p2)
{

	return (((p1.x<p2.x) || (p1.x == p2.x & p1.y<p2.y))) ? true : false ;
}
