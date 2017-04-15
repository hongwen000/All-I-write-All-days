class Date {
public:
    Date(int _year = 0, int _month = 1, int _day = 1)
        : year(_year), month(_month), day(_day) {}
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    Date operator++(int);
    Date operator--(int);
    Date& operator++();
    Date& operator--();

private:
    int year, month, day;
};

inline int getDayOfFeb(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
}

void plusHelper(int& year, int& month, int& day)
{
    int dayOfFeb = getDayOfFeb(year);
    if (month == 2) {
        if (day == dayOfFeb) {
            day = 1;
            month = 3;
        } else
            day++;
    } else if (month == 12) {
        if (day == 31) {
            day = 1;
            month = 1;
            ++year;
        } else
            ++day;
    } else
        ++day;
}

Date& Date::operator++()
{
    plusHelper(year, month, day);
    return *this;
}

Date Date::operator++(int)
{
    Date tmp = *this;
    ++*this;
    return tmp;
}

void subHelper(int& year, int& month, int& day)
{
    int dayOfFeb = getDayOfFeb(year);
    if (month == 3) {
        if (day == 1) {
            day = dayOfFeb;
            month = 2;
        } else {
            --day;
        }
    } else if (month == 1) {
        if (day == 1) {
            day = 31;
            month = 12;
            --year;
        } else {
            --day;
        }
    } else
        --day;
}

Date& Date ::operator--()
{
    subHelper(year, month, day);
    return *this;
}
Date Date::operator--(int)
{
    Date tmp = *this;
    --*this;
    return tmp;
}

