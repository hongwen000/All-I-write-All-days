#ifndef STUDENT_H
#define STUDENT_H
#include "Term.h"
using Observers = std::vector<LessonObserver*>;
class Student : public LessonObserver {
public:
	int NumberOfTerm = 0;
	int StudentId;
	int EntranceYear;
	int OverallCredit;
	double OverallGrade;
	int OverallCreditExpectPubEle;
	double OverallGradeExpectPubEle;
	bool TermsContentChanged;
	bool TermsChanged;
	string Name;
	string School;
	string Major;
	Term Terms[MAX_TERM_OF_STUDENT + 1];
	Student();
	void calcTermTillNow();
	void calcEntranceYear();
	int getStudentId();
	int getOverallCredit();
	double getOverallGrade();
	double getOverallGradeExpectPubEle();
	int getOverallCreditExpectPubEle();
	string getSchool();
	string getMajor();
	int getNumberOfTerm(int Year, int Term);
	int getTotalTermOfYear(int Year);
	string getName();
	Term* getTermHandle(int n);
	const Term& getTerm(int n);
	const Term& operator [](int n);
	int setName(string Name);
	int setStudentId(int StudentId);
	int setSchool(string School);
	int setMajor(string Major);
	void reNewStudentContentAfterTermsChanged();
	int print();
	int RefreshGpa(const Lesson* lesson);
	void Notify(const Lesson* lesson) override {
		RefreshGpa(lesson);
	}
};
#endif
