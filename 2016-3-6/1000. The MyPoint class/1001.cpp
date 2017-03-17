#include <iostream>
#include <string>
using namespace std;
class Fan
{
public:
  Fan();
  int getSpeed();
  void setSpeed(int);
  bool isOn();
  void setOn(bool);
  double getRadius();
  void setRadius(double);
  string getColor();
  void setColor(string);

  private:
    int speed;
    bool on;
    double radius;
    string color;
};
    Fan::Fan()
    {
    int speed=1;
    bool on=false;
    double radius=5;
    string color="blue";
    }
    int Fan::getSpeed()
    {
        return speed;
    }
    bool Fan::isOn()
    {
        return on;
    }
    void Fan::setOn(bool _on)
    {
        on=_on;
    }
    double Fan::getRadius()
    {
        return radius;
    }
    void Fan::setRadius(double _radius)
    {
        radius=_radius;
    }
    string Fan::getColor()
    {
        return color;
    }
    void Fan::setColor(string _color)
    {
        color=_color;
    }