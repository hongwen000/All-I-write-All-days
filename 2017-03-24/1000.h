#pragma once
#include <utility>
class Date 
{
public:
    Date(int newYear,int newMonth,int newDay) : year(newYear), month(newMonth), day(newDay) {};
	int getYear() { return year; }; 
	void setYear(int newYear) { year = newYear; }
	int getMonth() { return month; }
	int getDay() { return day; }
	void setMonth(int Month) { month = Month; }
	void setDay(int Day) { day = Day; }
private: 
	int year; 
	int month; 
	int day; 
};
class Person 
{ 
public: 
Person(int _id, int _year, int _month, int _day) : id(_id), birthDate(new Date(_year, _month, _day)) { 
    ++numberOfObjects;
} 
Person(const Person &rhs) : id(rhs.id), birthDate(new Date(*rhs.birthDate)) { //这儿不会写一开始
    ++numberOfObjects;
}
~Person() { 
    delete birthDate;
    --numberOfObjects;
}
int getId() { return id; }; 
Date * getBirthDate() { return birthDate; }
static int getNumberOfObjects() { return numberOfObjects; }//return the number of Person objects

private: 
int id; 
Date *birthDate; 
static int numberOfObjects; //count the number of Person objects 
};
int Person::numberOfObjects = 0;
