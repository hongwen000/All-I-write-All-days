#ifndef LESSON_H
#define LESSON_H
#include "Backend.h"
class Lesson{
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
    int Grade;
    string GetTime(int StartTime);
    Lesson();
    int init();
	string getGrade();
};
#endif
