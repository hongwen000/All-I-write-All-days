#include <iostream>
#include <cmath>
using namespace std;
class MyPoint
{
  private:
    double x, y;
  public:
    MyPoint();
    MyPoint(double x, double y);
    double getX();
    double getY();
    double distance(MyPoint &point);
};
MyPoint::MyPoint()
{
	x=0;
	y=0;
}
MyPoint::MyPoint(double x,double y)
{
	MyPoint::x=x;
	MyPoint::y=y;
}
double MyPoint::getX()
{
	return x;
}
double MyPoint::getY()
{
	return  y;
}
double MyPoint::distance(MyPoint &point)
{
	double distance(0);
	distance=sqrt(pow((x-(point.x)),2)+pow((y-(point.y)),2));
	return distance;
}
int main()
{
	MyPoint point1(1,1),point2(2,2);
	cout << point1.distance(point2);
	while(1){}
	return 0;
}