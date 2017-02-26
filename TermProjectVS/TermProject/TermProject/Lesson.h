#ifndef LESSON_H
#define LESSON_H
#include "Backend.h"
class Lesson;
class LessonObserver {
public:
	virtual void Notify(const Lesson*);
};
using Observers = std::vector<LessonObserver*>;
class Lesson{
	private:
	Observers observers_;
    public:
    int WeekTimes;
    int Term;
    int Year;
    string Name;
    string TeacherName;
    int Type;
    int Weekday[MAX_WEEK_TIMES];
    int StartWeek;
    int EndWeek;
    int StartTime[MAX_WEEK_TIMES];
    int EndTime[MAX_WEEK_TIMES];
	string Place[MAX_WEEK_TIMES];
    bool Finished;
	int Credit;
    double Grade_Ori;
	double Grade;
    string GetTime(int StartTime);
    Lesson();
    int init();
	string getGrade();
	void UpdateScore();
	void AttachObserver(LessonObserver *LessonObserver_);
};

#endif
