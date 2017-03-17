#include <string>
using namespace std;
class Fan {
    private:
        int speed;
        bool isON;
        double radius;
        string color;
    public:
        Fan() : speed(1), isON(false), radius(5), color("blue") {}
        int getSpeed() {
           return speed;
        }
        void setSpeed(int _speed) {
            speed = _speed;
        }
        bool isOn() {
           return isON;
        }
        void setOn(bool _isON) {
           isON = _isON;
        } 
        double getRadius() {
           return radius;
        }
        void setRadius(double _radius) {
           radius = _radius;
        }
        string getColor() {
           return color;
        }
        void setColor(string _color) {
            color = _color;
        }
};

#include <iostream>
using namespace std;
int main()
{
  cout << "First fan properties: " << endl;
  Fan fan;
  fan.setSpeed(3);
  fan.setRadius(10);
  fan.setOn(true);
  fan.setColor("yellow");

  cout << "Fan speed: " << fan.getSpeed() << endl;
  cout << "Fan radius: " << fan.getRadius() << endl;
  cout << "Fan on? " << fan.isOn() << endl;
  cout << "Fan color: " << fan.getColor() << endl;

  Fan fan1;
  fan.setSpeed(2);
  fan.setRadius(5);
  fan.setOn(false);
  fan.setColor("blue");

  cout << "\nSecond fan properties: " << endl;
  cout << "Fan speed: " << fan1.getSpeed() << endl;
  cout << "Fan radius: " << fan1.getRadius() << endl;
  cout << "Fan on? " << fan1.isOn() << endl;
  cout << "Fan color: " << fan1.getColor() << endl;


  return 0;
}

