// 1003. The Person, Student, Employee, Faculty ,Staff.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

class MyDate
{
public:
	MyDate();
	~MyDate();

private:
	int year;
	int month;
	int day;
};

MyDate::MyDate()
{
}

MyDate::~MyDate()
{
}

class Person
{
public:
	Person();
	~Person();
	virtual string toString()
	{
		return "Person"; 
	}
private:
	string name;
	string address;
	string phoneNumber;
	string email;

};

Person::Person()
{
}

Person::~Person()
{
}

class Student : public Person
{
public:
	Student();
	~Student();
	string toString()
	{
		return "Student";
	}
private:
	enum class_status { frssman, sophomore, junior, senior };
	class_status status;

};


Student::Student()
{
}

Student::~Student()
{
}

class  Employee : public Person
{
public:
	 Employee();
	~ Employee();
	virtual 	string toString()
	{
		return "Employee";
	}
private:
	string office;
	int salary;
	MyDate dateHired;
};

 Employee:: Employee()
{
}

 Employee::~ Employee()
{
}

 class Faculty : public Employee
 {
 public:
	 Faculty();
	 ~Faculty();
	 string toString()
	 {
		 return "Faculty";
	 }
 private:
	 string officeHours;
	 int rank;
 };

 Faculty::Faculty()
 {
 }

 Faculty::~Faculty()
 {
 }

 class Staff : public Employee
 {
 public:
	 Staff();
	 ~Staff();
	 string toString()
	 {
		 return "Staff";
	 }
 private:
	 string title;

 };

 Staff::Staff()
 {
 }

 Staff::~Staff()
 {
 }


 void f(Person &p)
 {
	 cout << p.toString() << endl;
 }
int main()
{
	Person person;
	Student student;
	Employee employee;
	Faculty faculty;
	Staff staff;
	f(person);
	f(student);
	f(employee);
	f(faculty);
	f(staff);
    return 0;
}

