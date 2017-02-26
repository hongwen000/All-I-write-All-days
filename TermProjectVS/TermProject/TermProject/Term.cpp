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
	//引入观察者模式后已经弃用
    //if(LessonsChanged)
    //{
    //    double SumOfCredit=0;
    //    double SumOfGrade=0;
    //    double SumOfCreditExpectPubEle=0;
    //    double SumOfGradeExpectPubEle=0;
    //    for(int i=0;i<NumberOfLesson;i++)
    //    {
    //        SumOfCredit+=Lessons[i].Credit;
    //        SumOfGrade+=Lessons[i].Credit*Lessons[i].Grade;
    //        SumOfCreditExpectPubEle+=(Lessons[i].Type==3?0:Lessons[i].Credit);
    //        SumOfGradeExpectPubEle+=(Lessons[i].Type==3?0:Lessons[i].Credit*Lessons[i].Grade);
    //    }
    //    this->TotalCredit=SumOfCredit;
    //    this->TotalCreditExpectPubEle=SumOfCreditExpectPubEle;
    //    this->Average=SumOfGrade/SumOfCredit;
    //    this->AverageExpectPubEle=SumOfGradeExpectPubEle/SumOfCreditExpectPubEle;
    //    this->LessonsChanged=false;
    //}
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
double Term::getAverage()
{
   reNew();
   return Average;
}
double Term::getAverageExpectPubEle()
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
		Point2Lesson->AttachObserver(this);
		getNumberOfLessonRefer()++;
	}
}
int Term::print()
{
	cout << CYAN << "  序号" << "  课程名                  "<<RESET<<endl;
        // cout  << "      " << "  英语学术阅读与写作I      "       << "  公必" << "  1   " << "12345678"<< "  暂无" <<  

	for (int i = 0; i < NumberOfLesson; i++) {
		cout << right<<setfill(' ') <<"  "<<BLUE<< setw(4) << i+1 <<left <<"  " << setw(25) << Lessons[i].Name <<RESET<<endl;
        cout <<left  <<CYAN<< "        类型:" <<setw(4) <<RESET<< LessonType[Lessons[i].Type-1]<<right<<CYAN<< "  学分:" <<RESET<<setw(4) << Lessons[i].Credit<<CYAN<<  "  老师:" <<RESET<<setw(8) << Lessons[i].TeacherName <<left<<CYAN<< "    成绩:" <<RESET<<setw(4)<< Lessons[i].getGrade()<<RESET<<endl;
		for (int j = 0; j < Lessons[i].WeekTimes; j ++) {
			cout << CYAN << "        上课时间" << j + 1 << "：" << RESET << "周" << Lessons[i].Weekday[j] << " " <<setw(5) << Lessons[i].GetTime(Lessons[i].StartTime[j]) << CYAN << "  地点：" << RESET << Lessons[i].Place[j]  <<RESET <<endl;
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
			cout << CYAN << "  上课时间" << j + 1 << "：" << RESET <<"周"<< Lessons[Rank].Weekday[j]<<" "<< Lessons[Rank].GetTime(Lessons[Rank].StartTime[j]) << CYAN << "  地点：" << Lessons[Rank].Place[j] << RESET << endl;
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
int Term::setGrade()
{
	for (int i = 0; i < NumberOfLesson; i++) {
		print(i);
		cout << "请输入该门课程成绩，暂无成绩则输入0" << endl;
		bool OK = false;
		int Input;
		while (!OK) {
			cin >> Input;
			if (Input <= 100 && Input >= 0) {
				Lessons[i].Finished = true;
				Lessons[i].Grade_Ori = Input;
				Lessons[i].Grade = (Lessons[i].Grade_Ori - 50) / 10.0;
				LessonsChanged = true;
				Lessons[i].UpdateScore();
				OK = true;
			}
		}
	}
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

int Term::sort(const char * Mode, bool ASC)
{
	if (!strcasecmp(Mode, "-n")) {
		if (ASC == true) {
			std::sort(Lessons.begin(), Lessons.begin() + NumberOfLesson, [](Lesson a, Lesson b) {return zh_CN_less_than(a.Name, b.Name) ? 1 : 0; });
		}
		else {
			std::sort(Lessons.begin(), Lessons.begin() + NumberOfLesson, [](Lesson a, Lesson b) {return zh_CN_less_than(a.Name, b.Name) ? 0 : 1; });
		}
	}
	else if ((!strcasecmp(Mode, "-w"))) {
		if (ASC == true) {
			std::sort(Lessons.begin(), Lessons.begin() + NumberOfLesson, [](Lesson a, Lesson b) {return (a.Weekday[0] < b.Weekday[0]) ? 1 : 0; });
		}
		else {
			std::sort(Lessons.begin(), Lessons.begin() + NumberOfLesson, [](Lesson a, Lesson b) {return (a.Weekday[0]  > b.Weekday[0]) ? 1 : 0; });
		}
	}
	else if ((!strcasecmp(Mode, "-t"))) {
		if (ASC == true) {
			std::sort(Lessons.begin(), Lessons.begin() + NumberOfLesson, [](Lesson a, Lesson b) {return (a.Type < b.Type) ? 1 : 0; });
		}
		else {
			std::sort(Lessons.begin(), Lessons.begin() + NumberOfLesson, [](Lesson a, Lesson b) {return (a.Type  > b.Type) ? 1 : 0; });
		}
	}
	else {

	}
}

int Term::RefreshGpa(const Lesson* lesson)
{
	Average = (TotalCredit*Average + (lesson->Credit*lesson->Grade)) / (TotalCredit + lesson->Credit);
	AverageExpectPubEle = (TotalCreditExpectPubEle*AverageExpectPubEle + (lesson->Type != 3 ? lesson->Credit : 0) * lesson->Grade) / (TotalCreditExpectPubEle + (lesson->Type != 3 ? lesson->Credit : 0));
	TotalCredit += lesson->Credit;
	TotalCreditExpectPubEle += lesson->Type != 3 ? lesson->Credit : 0;
	return 0;
}
