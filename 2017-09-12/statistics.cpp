#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<string> split_string(const std::string& strg) {
    auto range_low = 0;
    auto range_high = string::npos;
    vector<string> vec;
    while(true) {
        range_high = strg.find(',', range_low + 1);
        if(range_high == string::npos) {
            vec.emplace_back(strg.substr(range_low));
            break;
        }
        else
          vec.push_back(strg.substr(range_low, range_high - range_low));
        range_low = range_high;
    }
    return vec;
}

int strToSec(const std::string& s) {
    auto pos1 = s.find('|');
    auto pos2 = s.find('|', pos1 + 1);
    auto hour = s.substr(0, pos1);
    auto minu = s.substr(pos1 + 1, pos2 - pos1 - 1);
    auto secd = s.substr(pos2 + 1);
    auto ret = 3600 * stoi(hour) + 60 * stoi(minu) + stoi(secd);
    return ret;
} 

string secToStr(int sec) {
    auto hour = sec / 3600;
    auto minu = (sec - hour * 3600) / 60;
    auto secd = (sec - hour * 3600 - minu * 60);
    stringstream ret;
    ret << setw(2) << setfill('0') << hour;
    ret << "|";
    ret << setw(2) << setfill('0') << minu;
    ret << "|";
    ret << setw(2) << setfill('0') << secd;
    return ret.str();
}

class Stat
{
public:
  static std::string stat(const std::string& strg) 
  {
      if(strg == "")
          return "";
      auto vec = split_string(strg);
      if(vec.size() > 1)
        for(auto it = vec.begin() + 1; it != vec.end(); ++it)
          *it = it->substr(2);
      vector<int> secs;
      for(auto& s : vec)
          secs.push_back(strToSec(s));
      int min_time = *min_element(secs.begin(), secs.end()); 
      int max_time = *max_element(secs.begin(), secs.end()); 
      auto diff = max_time - min_time;
      auto sum = accumulate(secs.begin(), secs.end(), 0);
      int avag = sum / secs.size();
      sort(secs.begin(), secs.end());
      int median;
      if(secs.size() & 1)
         median = secs[secs.size() / 2];
      else
         median = (secs[secs.size() / 2] + secs[secs.size() / 2 - 1]) / 2;
      string s_diff = secToStr(diff);
      string s_avag = secToStr(avag);     
      string s_medi = secToStr(median);   
      return "Range: " + s_diff + " Average: " + s_avag + " Median: " + s_medi;
  }

};

int main()
{
    std::string l = "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17";
    cout << Stat::stat(l) << endl;

}
