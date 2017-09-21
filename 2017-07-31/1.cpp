#include <iostream>
using namespace std;
int main()
{
    const double current_GPA = 4.413;
    const double current_Credit = 31;
    const double today_Credit = 3;
    auto getTodayGPA = [=](double today_Grade) {
        double current_Sum = current_GPA * current_Credit;
        double today_GPA = (today_Grade - 50) / 10;
        double today_Sum = current_Sum + today_Credit * today_GPA;
        return today_Sum / (current_Credit + today_Credit);
    };
    for(int today_Grade = 100; today_Grade >= 60; --today_Grade)
        cout << today_Grade << '\t' << getTodayGPA(today_Grade) << endl;
}
