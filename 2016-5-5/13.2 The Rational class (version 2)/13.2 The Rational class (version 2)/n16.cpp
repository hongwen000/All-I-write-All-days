#include <iostream>
using namespace std;
class Date
{
public:
	Date(int y = 0, int m = 1, int d = 1);
	static bool leapyear(int year);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	friend bool operator == (const Date date1, const Date date2);
	friend bool operator != (const Date date1, const Date date2);
	friend bool operator < (const Date date1, const Date date2);
	friend bool operator <= (const Date date1, const Date date2);
	friend bool operator > (const Date date1, const Date date2);
	friend bool operator > (const Date date1, const Date date2);
	friend bool operator >= (const Date date1, const Date date2);
	Date operator++();
	Date operator--();
	Date operator++(int dummy);
	Date operator--(int dummy);
	//Date operator+();
	//Date operator-();
private:
	int year;
	int month;
	int day;
	// add any member you need here  
};

//You implementation should enable the usage like this:
//void f()
//{
//	Date date1, date2(2003, 1, 1);
//	Date date3 = Date(2007, 2, 28);
//	date3 = date1;
//
//	cout << "year 1996 is leap year? " << Date::leapyear(1996) << endl;
//	cout << "year 1200 is leap year? " << Date::leapyear(1200) << endl;
//	cout << "year 1300 is leap year? " << Date::leapyear(1300) << endl;
//	cout << "year 1999 is leap year? " << Date::leapyear(1999) << endl;
//
//	cout << "(date1==date3)? " << (date1 == date3) << endl;
//	cout << "(date1!=date3)? " << (date1 != date3) << endl;
//	cout << "(date1==date2)? " << (date1 == date2) << endl;
//	cout << "(date1!=date2)? " << (date1 != date2) << endl;
//
//	cout << "(date1<date1)? " << (date1<date1) << endl;
//	cout << "(date1<=date1)? " << (date1 <= date1) << endl;
//	cout << "(date1<date2)? " << (date1<date2) << endl;
//	cout << "(date1<=date2)? " << (date1 <= date2) << endl;
//
//	cout << "(date1>date1)? " << (date1>date1) << endl;
//	cout << "(date1>=date1)? " << (date1 >= date1) << endl;
//	cout << "(date1>date2)? " << (date1>date2) << endl;
//	cout << "(date1>=date2)? " << (date1 >= date2) << endl;
//}
//The output of f() should be :
//year 1996 is leap year ? 1
//year 1200 is leap year ? 1
//year 1300 is leap year ? 0
//year 1999 is leap year ? 0
//(date1 == date3) ? 1
//(date1 != date3) ? 0
//(date1 == date2) ? 0
//(date1 != date2) ? 1
//(date1<date1) ? 0
//	(date1 <= date1) ? 1
//	(date1<date2) ? 1
//	(date1 <= date2) ? 1
//	(date1>date1) ? 0
//	(date1 >= date1) ? 1
//	(date1>date2) ? 0
//	(date1 >= date2) ? 0
void f()
{
	Date date(2016, 3, 1);
	cout << "date = " << date.getYear() <<'-'<<date.getMonth()<<'-'<<date.getDay()<< endl;
	++date;
	cout << "++date = " << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << endl;
	--date;
	cout << "--date = " << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << endl;
	date--;
	cout << "date-- = " << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << endl;
	date++;
	cout << "date++ = " << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << endl;
	cout << "date = " << date.getYear() << '-' << date.getMonth() << '-' << date.getDay() << endl;
}
int main()
{
	f();
    return 0;
}

Date::Date(int y, int m, int d) :year(y),month(m),day(d)
{

}

bool Date::leapyear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

Date Date::operator++()
{
	if (month == 12 && day == 31) 
	{
		year++;
		month = 1;
		day = 1;
	}
	else	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8  || month == 10) && day == 31)
		{
			month++;
			day = 1;
		}
		else if (( month == 4|| month == 6 || month == 9 || month == 11 ) && day == 30)
		{
			month++;
			day = 1;
		}
		else if((month == 2 ) && (!this->leapyear(this->getYear())) && day == 28 )
		{
			month++;
			day = 1;
		}
		else if ((month == 2) && (this->leapyear(this->getYear())) && day == 29)
		{
			month++;
			day = 1;
		}
		else
		{
			day++;
		}
	return Date();
}

Date Date::operator--()
{
	if (day == 1 && month == 1)
	{
		day = 31;
		month = 12;
		year--;
	}
	else if (( month == 5 || month == 7 || month == 10 || month == 12) && day == 1)
	{
		day = 30;
		month--;
	}
	else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && day == 1)
	{
		day = 31;
		month--;
	}
	else if ((month == 3) && day == 1)
	{
		if ((this->leapyear(this->getYear())))
		{
			day = 29;
			month--;
		}
		else
		{
			day = 28;
			month--;
		}
	}
	else
	{
		day--;
	}
	return Date();
}

Date Date::operator++(int dummy)
{
	Date temp=*this;
	++(*this);
	return temp;
}

Date Date::operator--(int dummy)
{
	Date temp=*this;
	--(*this);
	return temp;
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
	return date1==date2 ? false : true ;
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