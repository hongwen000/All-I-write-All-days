#include <iostream>
#include "Time.hpp"
using namespace std;
 
int main() {
    Time time0 = Time();
    Time time1 = Time(1, 0);
    Time time2 = Time(23, 12, 34);
    Time time3 = Time(time2);
    cout << time0.toString() << endl;
    cout << time1.toString() << endl;
    cout << time2.toString() << endl;
    cout << time3.toString() << endl;
 
    int h, m, s, random;
    cin >> h >> m >> s >> random;
    Time* time = new Time();
    time->setHour(h);
    time->setMinute(m);
    time->setSecond(s);
 
    cout << "The time is: " << time->getHour() << ":"
        << time->getMinute() << ":" << time->getSecond() << endl;
    if (time->isValid()) {
        cout << "Formatted time is: " << time->toString() << endl;
        cout << "After " << random << " seconds, the time is: ";
        cout << time->after(random).toString() << endl;
    } else {
        cout << "The time is invalid!\n";
    }
    delete time;
}

