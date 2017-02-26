#include "Term.h"
Term::Term(){
    NumberOfLesson=0;
    Year=1924;
    Rank=1;
    TotalRank=0;
    TotalCredit=0;
    Average=0;
    AverageExpectPubEle=0;
    LessonsChanged=false;
    TotalCreditExpectPubEle=0;
	for (int i = 0; i <= MAX_LESSON_OF_TERM; i++) {
		Lesson temp;
		Lessons.push_back(temp);
	}
}
int Term::setYear(int Year)
{
    this->Year=Year;
    for(int i=1;i<=MAX_LESSON_OF_TERM;i++)
        Lessons[i].Year=Year;
    return 0;
}
int Term::setRank(int Rank)
{
    this->Rank=Rank;
    for(int i=1;i<=MAX_LESSON_OF_TERM;i++)
        Lessons[i].Term=Rank;
    return 0;
}
int Term::setTotalRank(int TotalRank)
{
    this->TotalRank=TotalRank;
    return 0;
}

void Term::reNew()
{
    if(LessonsChanged)
    {
        int SumOfCredit=0;
        int SumOfGrade=0;
        int SumOfCreditExpectPubEle=0;
        int SumOfGradeExpectPubEle=0;
        for(int i=0;i<NumberOfLesson;i++)
        {
            SumOfCredit+=Lessons[i].Credit;
            SumOfGrade+=Lessons[i].Credit*Lessons[i].Grade;
            SumOfCreditExpectPubEle+=(Lessons[i].Type==3?0:Lessons[i].Credit);
            SumOfGradeExpectPubEle+=(Lessons[i].Type==3?0:Lessons[i].Credit*Lessons[i].Grade);
        }
        this->TotalCredit=SumOfCredit;
        this->TotalCreditExpectPubEle=SumOfCreditExpectPubEle;
        this->Average=SumOfGrade/SumOfCredit;
        this->AverageExpectPubEle=SumOfGradeExpectPubEle/SumOfCreditExpectPubEle;
        this->LessonsChanged=false;
    }
}
int Term::getCredit()
{
    reNew();
    return TotalCredit;
}
int Term::getCreditExpectPubEle()
{
    reNew();
    return TotalCreditExpectPubEle;
}
int Term::getAverage()
{
   reNew();
   return Average;
}
int Term::getAverageExpectPubEle()
{
   reNew();
   return AverageExpectPubEle;
}
int& Term::getNumberOfLessonRefer()
{
    return NumberOfLesson;
}
Lesson* Term::getLessonHandle(int n)
{
	char argv[MAX_COMMAND_CHAR];
	sprintf(argv, "%d", n);
	if (n>getNumberOfLessonRefer())
		throwError(ACCESS_VIOLATION, "Read Lessons", argv);
	return &Lessons[n];
}
//Lesson* Term::newLessonHandle(int n)
//{
//	char argv[MAX_COMMAND_CHAR];
//	sprintf(argv, "%d", n);
//	if (n == getNumberOfLessonRefer()) {
//		if (n == MAX_STUDENTS_NUM)
//			throwError(STORAGE_FULL, "Write Lessons", argv);
//		Lesson temp;
//		Lessons.push_back(temp);
//	}
//	else if (n>getNumberOfLessonRefer())
//		throwError(ACCESS_VIOLATION, "Write Lessons", argv);
//	return &Lessons[n];
//}

int Term::Add()
{
	if (NumberOfLesson == MAX_LESSON_OF_TERM)
		throwError(STORAGE_FULL, "Add Lesson", string("You CANNOT Storage More Lesson in This Term"));
	else {
		Lesson* Point2Lesson=this->getLessonHandle(getNumberOfLessonRefer());
		Point2Lesson->Finished = true;
		Point2Lesson->init();
		getNumberOfLessonRefer()++;
	}
}
int Term::print()
{
	cout << CYAN << "  序号" << "  课程名           " <<left<< "  类型" <<right<< "  学分" << "  老师  " <<left<< "    成绩" <<RESET<<endl;
        // cout  << "     " << "  英语学术阅读与写作I" << "  公必" << "  1   " << "12345678"<< "  暂无" <<  

	for (int i = 0; i < NumberOfLesson; i++) {
		cout << setfill(' ') <<"  "<< setw(4) << i+1 <<left <<"  " << setw(19) << Lessons[i].Name << "  " << setw(4) << LessonType[Lessons[i].Type-1] << "  " << setw(4) << Lessons[i].Credit << "  " << setw(8) << Lessons[i].TeacherName << "  " << Lessons[i].getGrade() << endl;
		for (int j = 0; j < Lessons[i].WeekTimes; j ++) {
			cout << CYAN << "  上课时间" << j + 1 << "：" << RESET << Lessons[i].GetTime(Lessons[i].StartTime[j]) << CYAN << "  地点：" << RESET << Lessons[i].Place[j]  << endl;
		}
	}
    return 0;
}
int Term::print(int Rank)
{
	cout << CYAN << "  序号" << "  课程名           " << "  类型" << "  学分" << "    老师" << "  成绩" << RESET << endl;
	// cout  << "     " << "  英语学术阅读与写作I" << "  公必" << "  1   " << "12345678"<< "  暂无" <<  
		cout << setfill(' ') << "  " << setw(4) << Rank + 1 << left << "  " << setw(22) << Lessons[Rank].Name << "  " << setw(4) << LessonType[Lessons[Rank].Type - 1] << "  " << setw(4) << Lessons[Rank].Credit << "  " << setw(8) << Lessons[Rank].TeacherName << "  " << Lessons[Rank].getGrade() << endl;
		for (int j = 0; j < Lessons[Rank].WeekTimes; j++) {
			cout << CYAN << "  上课时间" << j + 1 << "：" << RESET << Lessons[Rank].GetTime(Lessons[Rank].StartTime[j]) << CYAN << "  地点：" << Lessons[Rank].Place[j] << RESET << endl;
	}
	return 0;
}
int Term::del(int n)
{
	vector<Lesson>::iterator it = Lessons.begin() + n;
	Lessons.erase(it);
	Lesson temp;
	Lessons.push_back(temp);
	getNumberOfLessonRefer()--;
	return 0;
}
int Term::Find(int Rank, const char* Mode, int LastSearch)
{
	if (!strcasecmp(Mode,"-r")) {
		//bool found = false;
		//for (int i = 0; i<getNumberOfLessonRefer(); i++) {
		//	if (this->getLessonHandle(i)-> == StudentId) {
		//		found = true;
		//		return i;
		//	}
		//}
		//if (!found)
		//	return NOT_FOUND_STUDENTID;
		return Rank;
	}
	else if (!strcasecmp(Mode,"-w")) {
		bool found = false;
		for (int i = LastSearch; i<getNumberOfLessonRefer(); i++) {
			for (int j = 0; j < this->getLessonHandle(i)->WeekTimes; j++) {
				if (this->getLessonHandle(i)->Weekday[j] == Rank) {
					found = true;
					return i;
				}
			}
		}
		if (!found)
			return NOT_FOUND_LESSON;
	}
	else if (!strcasecmp(Mode,"-t")) {
		bool found = false;
		for (int i = LastSearch; i<getNumberOfLessonRefer(); i++) {
			if (this->getLessonHandle(i)->Type == Rank) {
				found = true;
				return i;
			}
		}
		if (!found)
			return NOT_FOUND_LESSON;
	}

	else {
		return 0;
	}
}
int Term::Find(string Name, const char* Mode, int LastSearch)
{
	if (!strcasecmp(Mode,"-r")) {
		//bool found = false;
		//for (int i = 0; i<getNumberOfLessonRefer(); i++) {
		//	if (this->getLessonHandle(i)-> == StudentId) {
		//		found = true;
		//		return i;
		//	}
		//}
		//if (!found)
		//	return NOT_FOUND_STUDENTID;
		return Rank;
	}
	else if(!strcasecmp(Mode,"-n")) {
		bool found = false;
		for (int i = LastSearch; i<getNumberOfLessonRefer(); i++) {
			if (this->getLessonHandle(i)->Name == Name) {
				found = true;
				return i;
			}
		}
		if (!found)
			return NOT_FOUND_LESSON;
	}
	else {
		return 0;
	}
}
