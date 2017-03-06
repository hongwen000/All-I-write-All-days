/*--------------------------------------------------------------
 * This is an program to calcuate the tendence of ..., you know
 * will output daily finance situation of an account to an csv
 * file so that it can be visualized using excel
 * -------------------------------------------------------------
 *  Term types of finance :  
 *  Fixed
 *  Deposit
 *  Income
 *  -----------------------------------------------------------
 *  Everyday an account query every term How many they have
 *------------------------------------------------------------*/                    
#include <string>
#include <vector>
using namespace std;
namespace epsol {
    namespace Time {
        vector<string> now();
    };
};
class Time {
public:
    Time() : time(epsol::Time::now()) { }
    Time(vector<string> te) : time(te) { }
    Time(string yr, string mh, string dy, string hr = "0", string mn = "0", string sc = "0")
    {
        time.push_back(yr);
        time.push_back(mh);
        time.push_back(dy);
        time.push_back(hr);
        time.push_back(mn);
        time.push_back(sc);
    }
    virtual vector<string> get() const { return time; }
    virtual ~Time() = default;
    //Todo : use factory to ensure the security of this constructor
protected:
    vector<string> time;
};
class Date : Time {
public:
    vector<string> get() const override {
        vector<string> date( {time[0], time[1], time[2]} );
        return date;
    }
};
bool operator== (const Time &lhs, const Date &rhs) 
{
    return (lhs.get())[0] == (rhs.get())[0] \
    && (lhs.get())[1] == (rhs.get())[1]     \
    && lhs.get()[2] == rhs.get()[2];
}
class Fixed {
public:
    Fixed() = delete;
    Fixed(long double m_c, string ne = "no name", bool dy = false) : money_count(m_c), name(ne), daily(dy){ }
    virtual long double get() { return money_count; }
    virtual ~Fixed();
protected:
    long double money_count;
    string name;
    Time creation_time;
    bool daily;//Once or every day
};
class Deposit : Fixed {
protected:
    long double deposit_ratio; 
};
class Income : Fixed {
protected:
    long double daily_income;
};
class account {
    string name;
    vector<Fixed> terms;
    Time creation_time;
};

    
    
