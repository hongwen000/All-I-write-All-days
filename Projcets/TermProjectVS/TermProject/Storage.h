#ifndef STORAGE_H
#define STORAGE_H
#include "Student.h"
class Storage{
    private:
//        Student Students[MAX_STUDENTS_NUM];
        vector<Student> Students;
        int TotalStudentNumber;
    public:
        int& getTotalStudentNumberRefer();
        Storage();
        const Student& getStudent(int n);
        const Student& operator [](int n);
        Student* getStudentHandle(int n);
		Student * newStudentHandle(int n);
        int Add();
		int Add(int StudentId, string StudnetName);
        int Find(int StudentId,const char* mode=string("-i").c_str(), int LastSearch = 0);
		int Find(string Name, const char* mode=string("-n").c_str(), int LastSearch = 0);
        int print();
		int print(int Rank);
		int del(int StudentId);
		bool cmp(const Student a, const Student b, const char* Mode= string("-n").c_str(), bool ASC=true);
		int sort(const char * Mode=string("-i").c_str(), bool ASC=true);
};
#endif
