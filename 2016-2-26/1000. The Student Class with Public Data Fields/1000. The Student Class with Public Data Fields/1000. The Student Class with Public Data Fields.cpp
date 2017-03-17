// 1000. The Student Class with Public Data Fields.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdafx.h"
#include <iostream>
using namespace std;
#include <string>
class Student {
public:
	int id;
	char name[50]; // Data field
	int age;
	void set(Student & student, int _id, char * _name, int _age);
	Student();
	Student(int, char*, int);
	Student(int);
	void print(Student);
};




void Student::set(Student & student, int _id, char * _name, int _age)
{
	student.age = _age;
	student.id = _id;
	strcpy_s(student.name, _name);
}
Student::Student()
{

}
Student::Student(int _id, char * _name, int _age)
{
	Student::age = _age;
	Student::id = _id;
	strcpy_s(Student::name, _name);
}
Student::Student(int _id)
{
	strcpy_s(name, "No Name");
	age = 0;
	id = _id;
}
void Student::print(Student student)
{
	cout << student.name << " (" << student.id << ") is " << student.age << " years old." << endl;
}
int main() {
	Student std1, std2(123, "John Smith", 18), std3(124);
	std1.set(std1, 100, "Bill Gates", 61);
	std1.print(std1);
	std2.print(std2);
	std3.print(std3);
	return 0;
}


