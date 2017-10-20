#include <map>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    using T_day   = vector<double>;
    using T_month = map<int, T_day>;
    using T_year  = map<int, T_month>;
    map<int, T_year> data;
    const string filename = "Tmax_adj_final.txt";
    ifstream file(filename);
    string line;
    int year, month, day;
    while(std::getline(file, line)) {
        stringstream ss(line);
        ss >> year >> month >> day;
        double tmp;
        while(!ss.eof())
            data[year][month][day].push_back(tmp);
    }
    cout << "Read file OK" << endl;
    while(true) {
    cin >> year >> month >> day;
    int station;
    cin >> station;
    if(station > data[year][month][day].size())
        cout << "Error: no data of station " << station << " this day" << endl;
    else
        cout << data[year][month][day][station] << endl;
    }
}

    

        
