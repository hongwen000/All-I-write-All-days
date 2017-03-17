// 1002. The Date class (version 4).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
using namespace std;

class Date
{
public:
	Date(int y = 0, int m = 1, int d = 1) :year(y), month(m), day(d) {  }
	static bool leapyear(int year);
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	Date& operator+=(int);
	Date& operator-=(int);
	Date operator++(int dummy);
	Date operator--(int dummy);
	Date& operator++();
	Date& operator--();
	int& operator[](string);
	void standardlize();
	friend Date operator+(const Date&, int);
	friend Date operator-(const Date&, int);
	friend bool operator == (const Date date1, const Date date2);
	friend bool operator != (const Date date1, const Date date2);
	friend bool operator < (const Date date1, const Date date2);
	friend bool operator <= (const Date date1, const Date date2);
	friend bool operator > (const Date date1, const Date date2);
	friend bool operator > (const Date date1, const Date date2);
	friend bool operator >= (const Date date1, const Date date2);
private:
	int year;
	int month;
	int day;
};



int lyear[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int nlyear[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int sumlyear[13];
int sumnlyear[13];

void iniSumYear()
{
	for (int i = 1; i <= 12; i++)
	{
		sumlyear[i] = sumlyear[i - 1] + lyear[i];
		sumnlyear[i] = sumnlyear[i - 1] + nlyear[i];
	}
}

void Date::standardlize()
{
	for (int i = 1; i <= month; i++)
	{
		if (leapyear(year))            day += lyear[i - 1];
		else                                day += nlyear[i - 1];
	}
	month = 1;
	while (day >= (leapyear(year) ? 366  :  365))
	{
		if (leapyear(year))
		{
			day -= 366;
			year++;
		}
		else
		{
			day -= 365;
			year++;
		}
	}
	while (day <= 0)
	{
		if (leapyear(year - 1))
		{
			day += 366;
			year--;
		}
		else
		{
			day += 365;
			year--;
		}
	}
	for (int i = 0; i <= 11; i++)
	{
		if (leapyear(year) && day > sumlyear[i] && day <= sumlyear[i + 1])
		{
			month = i + 1;
			day = day - sumlyear[i];
			break;
		}
		if (!leapyear(year) && day > sumnlyear[i] && day <= sumnlyear[i + 1])
		{
			month = i + 1;
			day = day - sumnlyear[i];
			break;
		}
	}
}



bool Date::leapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	return false;
}


Date& Date::operator+=(int mday)
{
	day += mday;
	standardlize();
	return *this;
}

Date& Date::operator-=(int  mday)
{
	day -= mday;
	standardlize();
	return *this;
}

Date operator+(const Date& date1, int  mday)
{
	Date temp(date1.getYear(), date1.getMonth(), date1.getDay() + mday);
	temp.standardlize();
	return temp;
}

Date operator-(const Date& date1, int mday)
{
	Date temp(date1.getYear(), date1.getMonth(), date1.getDay() - mday);
	temp.standardlize();
	return temp;
}

Date Date::operator++(int dummy)
{
	Date temp(year, month, day);
	day++;
	temp.standardlize();
	standardlize();
	return temp;
}

Date Date::operator--(int dummy)
{
	Date temp(year, month, day);
	day--;
	temp.standardlize();
	standardlize();
	return temp;
}

Date& Date::operator++()
{
	day++;
	standardlize();
	return *this;
}

Date& Date::operator--()
{
	day--;
	standardlize();
	return *this;
}
bool operator==(const Date date1, const Date date2)
{
	if (date1.getDay() == date1.getDay() && date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Date date1, const Date date2)
{
	return date1 == date2 ? false : true;
}

bool operator<(const Date date1, const Date date2)
{

	if (date1.getYear() < date2.getYear())
	{
		return true;
	}
	else if (date1.getYear() == date2.getYear())
	{
		if (date1.getMonth() < date2.getMonth())
		{
			return true;
		}
		else if (date1.getMonth() == date2.getMonth())
		{
			if (date1.getDay() < date2.getDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool operator<=(const Date date1, const Date date2)
{
	return (date1 == date2 || date1 < date2) ? true : false;

}

bool operator>(const Date date1, const Date date2)
{
	return (date1 <= date2) ? false : true;
}
bool operator>=(const Date date1, const Date date2)
{
	return (date1 < date2) ? false : true;
}

int& Date::operator[](string key)
{
	if ("year" == key)
	{
		return year;
	}
	else if ("month" == key)
	{
		return month;
	}
	else
	{
		return day;
	}
}
int main()
{
	iniSumYear();

}
