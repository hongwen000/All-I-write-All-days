#ifndef TERM_H
#define TERM_H
#include "Lesson.h"
class Term{
    private:
        int Average;
        int AverageExpectPubEle;
        int TotalCredit;
        int TotalCreditExpectPubEle;
    public:
        int Year;
        int TotalRank;
        int Rank;
		vector<Lesson> Lessons;
        bool LessonsChanged;
        int NumberOfLesson;
        Term();
        int setYear(int Year);
        int setRank(int Rank);
        int setTotalRank(int TotalRank);
        void reNew();
        int getCredit();
        int getCreditExpectPubEle();
        int getAverage();
        int getAverageExpectPubEle();
        int& getNumberOfLessonRefer();
		Lesson * getLessonHandle(int n);
		int TermRankOfLastTerm;
		int Add();
        int print();
		int print(int Rank);
		int del(int n);
		int Find(int Rank, const char* Mode = string("-r").c_str(), int LastSearch=0);
		int Find(string Name, const char* Mode = string("-n").c_str(),int LastSearch=0);
};
#endif
