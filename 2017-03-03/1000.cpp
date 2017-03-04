#include <iomanip>
#include <cmath>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class triangle {
    private:
        vector<pair<double, double>> position;
    public:
        triangle() : position({make_pair(0.0, 0.0), make_pair(0.0, 0.0), make_pair(0.0, 0.0), make_pair(0.0, 0.0)}) { }
        triangle(double x1, double y1, double x2, double y2, double x3, double y3) : 
            position({make_pair(0.0, 0.0), make_pair(x1, y1), make_pair(x2, y2), make_pair(x3,y3)}) { }
        double getAera();
};
double triangle::getAera() 
{
    double xA = position[1].first - position[2].first;
    double yA = position[1].second - position[2].second; 
    double xB = position[3].first - position[2].first;
    double yB = position[3].second - position[2].second;
    double aera = fabs(xA * yB - xB * yA) * 0.5;
    return aera;
}
int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    triangle obj(x1, y1, x2, y2, x3, y3);
    cout << fixed << setprecision(2) << obj.getAera() << endl; 
    return 0;
}
