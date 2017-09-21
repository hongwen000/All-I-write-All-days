#include <iomanip>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    using T_day = vector<double>;
    using T_month = map<int, T_day>;
    using T_year = map<int, T_month>;
    map<int, T_year> data;
    const string filename = "Tmax_adj_final.txt";
    //const string filename = "Tless.txt";
    ifstream file(filename);
    string line;
    int year, month, day;
    while (std::getline(file, line)) {
        stringstream ss(std::move(line));
        ss >> year >> month >> day;
        double tmp;
        while (!ss.eof()) {
            ss >> tmp;
            data[year][month][day].push_back(tmp);
        }
    }
    cout << "Read file OK" << endl;
    int rl, rh;
    while (true) {
        cin >> rl >> rh;
        if(rl == -1)
            break;
        cout << "Showing station data, from station " << rl << " to " << rh << endl;
        for (auto& year_data : data) {
            year = year_data.first;
            for (auto& month_data : year_data.second) {
                month = month_data.first;
                for (auto& day_data : month_data.second) {
                    day = day_data.first;
                    cout << year << '\t' << month << '\t' << day << '\t';
                    for (int i = rl - 1; i <= rh - 1; ++i) {
                        cout.flags(ios::right);
                        cout << setw(9) << fixed << setprecision(1) << day_data.second[i] << '\t';
                    }
                    cout << endl;
                }
            }
        }
    }
}
