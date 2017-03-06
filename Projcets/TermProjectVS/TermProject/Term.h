#ifndef TERM_H
#define TERM_H
#include "Lesson.h"
class Term : public LessonObserver {
    private:
        double Average;
        double AverageExpectPubEle;
		double TotalCredit;
		double TotalCreditExpectPubEle;
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
        double getAverage();
        double getAverageExpectPubEle();
        int& getNumberOfLessonRefer();
		Lesson * getLessonHandle(int n);
		int TermRankOfLastTerm;
		int Add();
        int print();
		int print(int Rank);
		int del(int n);
		int setGrade();
		int Find(int Rank, const char* Mode = string("-r").c_str(), int LastSearch=0);
		int Find(string Name, const char* Mode = string("-n").c_str(),int LastSearch=0);
		int sort(const char * Mode = string("-w").c_str(), bool ASC = true);
		int RefreshGpa(const Lesson* lesson);
		void Notify(const Lesson* lesson) override {
			RefreshGpa(lesson);
		}
};
#endif
