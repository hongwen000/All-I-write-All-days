#include "Storage.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "json/json.h"
using namespace std;
namespace js = Json;
Selection CurrentSelect;
Time CurrentTime;
Storage Students;
string LessonType[4] = {"公必","专必","专选","公选"};
string DaysOfWeekName[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
void throwError(int ErrorLevel, string ErrorProcedure,const char *argv)
{
            Error ErrorInstance;
            ErrorInstance.ErrorLevel=ErrorLevel;
            ErrorInstance.ErrorProcedure=ErrorProcedure;
            strcpy_s(ErrorInstance.ErrorArgv,MAX_COMMAND_CHAR,argv);
            throw ErrorInstance;
}
void throwError(int ErrorLevel, string ErrorProcedure,string ErrorMessage)
{
            Error ErrorInstance;
            ErrorInstance.ErrorLevel=ErrorLevel;
            ErrorInstance.ErrorProcedure=ErrorProcedure;
            ErrorInstance.ErrorMessage=ErrorMessage;
            memset(ErrorInstance.ErrorArgv,0,256);
            throw ErrorInstance;
}
void throwWarning(int ErrorLevel, string ErrorProcedure,const char *argv,string ErrorMessage)
{
    switch(ErrorLevel){
        case ACCESS_UNREASONABLE:{
            cout<<"Warning: Unreasonable Access During "<<RED<<ErrorProcedure<<RESET<<endl;
            break;
        }
        case INVAILD_INPUT:{
            cout<<"Warning: Invaild Input During "<<RED<<ErrorProcedure<<RESET<<endl;
            break;
        }
        default:
            break;
    }
    cout<<"During Processing Argument "<<RED<<argv<<RESET<<endl;    
    if(!ErrorMessage.empty())
        cout<<RED<<ErrorMessage<<RESET<<endl;
}
int MY_strcmp(const char* Command, const char* Input, bool EnableShort)
{
    if(EnableShort)
        return (strcmp(Input,Command)&&strcasecmp(Input,Command)&&!(Input[0]==Command[0]));
    else
        return (strcmp(Input,Command)&&strcasecmp(Input,Command));
}
static const locale zh_CN_locale = locale(ZH_CN_LOCALE_STRING);
static const collate<char>& zh_CN_collate = use_facet<collate<char> >(zh_CN_locale);
bool zh_CN_less_than(const string & s1, const string & s2)
{
	const char *pb1 = s1.data();
	const char *pb2 = s2.data();
	return (zh_CN_collate.compare(pb1, pb1 + s1.size(), pb2, pb2 + s2.size()) < 0);
}

char* strcpy_s(char *dest,size_t destsz, const char *src)
{
    size_t len=strlen(src);
    return len<=destsz?strcpy(dest,src):strcpy(dest,"");
}
int vaildStudentId(const char InputStudentId[])
{
    int StudentId=atoi(InputStudentId);
    if(StudentId<10000000 || StudentId>100000000)
        return 0;
//  if(!findStudentId(StudentId))
//      return 0;
    return StudentId;
}
    
int vaildTerm(const char InputTerm[])
{
    //To do
    int Term=atoi(InputTerm);
    if(Term<1||Term>MAX_TERM_OF_STUDENT)
        return 0;
    return Term;
}
int vaildYear(const char InputYear[])
{
    int Year=atoi(InputYear);
    if(Year<1924||Year>CurrentTime.getYear())
        return 0;
    return Year;
}
void help(initializer_list<string> argv)
{
    bool found=true;
    auto beg=argv.begin();
    if(argv.size()==1)
    {
        if(!MY_strcmp("select",(*beg).c_str())){
            cout<<"可用参数    "<<"用法"<<RESET<<endl;
			cout<<"student     "<<"后接学生学号，如"<<BOLDMAGENTA<<"select student 15323032"<<RESET<<RESET<<endl;
			cout<<"year        "<<"后接学年    ，如"<<BOLDMAGENTA<<"select year    2016"<<RESET<<RESET<<endl;
			cout<<"term        "<<"后接学期    ，如"<<BOLDMAGENTA<<"select term    1"<<RESET<<RESET<<endl;
            ++beg;
        }
        else{
            found=false;
        }
    }
    if(!found)
    {
    cout <<"没有找到"<<BOLDMAGENTA<<(*(argv.begin()))<<RESET<<"的帮助。";
    for(auto beg=argv.begin()+1;beg!=argv.end();++beg)
        cout <<"在模块"<<BOLDMAGENTA<<*beg<<RESET<<"中";
    cout <<endl;
    return;
    }
}
int origin::select(int argc, char *argv[])
{
    if(argc<=2 || argc%2!=0){
        help({"select"});
    }
    int i=2;
    while(i<argc){
        if(!MY_strcmp("student",argv[i])){
            if(!(CurrentSelect.StudentId=vaildStudentId(argv[++i]))){
                throwError(INVAILD_INPUT,"Select Student",argv[i]);
                }
            cout <<"Successfully Selected Student "<<CYAN<<CurrentSelect.StudentId<<RESET<<", Now You Need To Select"<<BOLDMAGENTA<<" Year "<<RESET<<"and"<<BOLDMAGENTA<<" Term"<<RESET<<endl;   
            CurrentSelect.Selected=false;
        }
		else if (!MY_strcmp("rank", argv[i])) {
			int n = atoi(argv[++i]);
			if (n <= 0 || n > Students.getTotalStudentNumberRefer()) {
				throwError(INVAILD_INPUT, "Select Student", argv[i]);
			}
			if (!(CurrentSelect.StudentId = (Students.getStudentHandle(n-1)->getStudentId()))) {
				throwError(INVAILD_SELECTION, "Select Student", argv[i]);
			}
			cout << "Successfully Selected Student " << CYAN << CurrentSelect.StudentId << RESET << ", Now You Need To Select" << BOLDMAGENTA << " Year " << RESET << "and" << BOLDMAGENTA << " Term" << RESET << endl;
			CurrentSelect.Selected = false;
		}
        else if (!MY_strcmp("year",argv[i])){
            int result=CurrentSelect.CurrentYear=vaildYear(argv[++i]);
            if(!result){
                throwError(INVAILD_INPUT,"Select Year",argv[i]);
                }
            if(INVAILD_SELECTION==result){
                throwError(INVAILD_SELECTION,"Select Year",argv[i]);
                }
            cout <<"Successfully Selected Year "<<CYAN<<CurrentSelect.CurrentYear<<RESET<<", Now You Need To Select"<<BOLDMAGENTA<<" Term"<<RESET<<endl;   
        }
        else if(!MY_strcmp("term",argv[i])){
            int result=CurrentSelect.CurrentTerm=vaildTerm(argv[++i]);
            if(!result){
                throwError(INVAILD_INPUT,"Select Term",argv[i]);
                }
            if(INVAILD_SELECTION==result){
                throwError(INVAILD_SELECTION,"Select Term",argv[i]);
                }
            cout <<"Successfully Selected Term "<<CYAN<<CurrentSelect.CurrentTerm<<RESET<<endl;
            CurrentSelect.Selected=true;
        }
        else{
            throwError(INVAILD_INPUT,"Selection",argv[i]);
        }
        i++;
    }
    return 0;
}
int origin::add(int argc, char *argv[])
{
    if(argc<=2){
        help({"add"});
    }
    else if(argc==3){
		int i = 2;
        if(!MY_strcmp("student",argv[i])){
            Students.Add();
        }
        else if(!MY_strcmp("lesson",argv[i])){
            if(CurrentSelect.Selected==false){
                throwError(NOT_HAVE_SELECTED,"add lesson",string("Now You Have Selected Student ")+string(to_string(CurrentSelect.StudentId))+string(" Year ")+string(to_string(CurrentSelect.CurrentYear))+string(" Term ")+string(to_string(CurrentSelect.CurrentTerm)));
            }
            Student* Point2Student=Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
            Term* Point2Term=Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear,CurrentSelect.CurrentTerm));
			Point2Term->LessonsChanged = true;
			Point2Student->TermsChanged = true;
			if (Point2Term->getNumberOfLessonRefer() == MAX_LESSON_OF_TERM)
				throwError(STORAGE_FULL, "Add Lesson", string("You CANNOT Storage More Lesson in This Term"));
			Lesson *Point2Lesson = Point2Term->getLessonHandle(Point2Term->getNumberOfLessonRefer());
			Point2Lesson->AttachObserver(Point2Student);
			Point2Term->Add();
			//给自己挖的坑...跪着也要填上
        }
        else{
            throwError(INVAILD_INPUT,"Addition",argv[i]);
        }
    }
	else if (argc == 5) {
		int i = 2;
		if (!MY_strcmp("student", argv[i])) {
			Students.Add(atoi(argv[3]),string(argv[4]));
		}
		else if (!MY_strcmp("lesson", argv[i])) {
			if (CurrentSelect.Selected == false) {
				throwError(NOT_HAVE_SELECTED, "add lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
			}
			Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
			Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
			Point2Term->LessonsChanged = true;
			Point2Student->TermsChanged = true;
			Point2Term->Add();
		}
		else {
			throwError(INVAILD_INPUT, "Addition", argv[i]);
		}

	}
	return 0;
}
int origin::del(int argc, char *argv[])
{
	if (argc <= 3) {
		help({ "delete" });
	}
	if (argc == 4) {
		if (!MY_strcmp("student", argv[2])) {
			int StudentId;
			if (!(StudentId = vaildStudentId(argv[3]))) {
				throwError(INVAILD_INPUT, "Delete Student", argv[3]);
			}
			Students.del(StudentId);
		}
		else if (!MY_strcmp("lesson", argv[2])) {
			if (CurrentSelect.Selected == false) {
				throwError(NOT_HAVE_SELECTED, "Delete Lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
			}
			Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
			Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
			int LessonRank = atoi(argv[3]);
			if (LessonRank > Point2Term->getNumberOfLessonRefer() || LessonRank <= 0)
				throwError(INVAILD_SELECTION, "Delete Lesson", argv[3]);
			Point2Term->del(LessonRank);
		}
		else if (!MY_strcmp("rank", argv[2])) {
			int n = atoi(argv[3]);
			int StudentId;
			if (n <= 0 || n > Students.getTotalStudentNumberRefer()) {
				throwError(INVAILD_INPUT, "Delete Student", argv[3]);
			}
			if (!(StudentId = (Students.getStudentHandle(n-1)->getStudentId()))) {
				throwError(INVAILD_SELECTION, "Delete Student", argv[3]);
			}
			Students.del(StudentId);
		}
		else {
			throwError(INVAILD_INPUT, "Deletion", argv[2]);
		}
	}

    return 0;
}
int origin::find(int argc, char *argv[])
{
	if (argc <= 4) {
		help({ "find" });
	}
	if (argc == 5) {
		if (!MY_strcmp("student", argv[2])) {
			if (!MY_strcmp("-i",argv[3],false)) {
				int StudentId;
				if (!(StudentId = vaildStudentId(argv[4]))) {
					throwError(INVAILD_INPUT, "Find Student", argv[4]);
				}
				int Rank=Students.Find(StudentId);
				if (StudentId == NOT_FOUND_STUDENTID)
					throwError(NOT_FOUND_STUDENTID, "Find Student by ID", argv[4]);
				Students.print(Rank);
			}
			else if (!MY_strcmp("-n", argv[3], false)) {
				string Name = string(argv[4]);
				int Rank = Students.Find(Name);
				if (Rank == NOT_FOUND_STUDENTID)
					throwError(NOT_FOUND_STUDENTID, "Find Student by Name", argv[4]);
				Students.print(Rank);
			}
			else if(!MY_strcmp("-r",argv[3],false)) {
				int Rank = atoi(argv[4]);//Attention
				if (Rank <= 0 || Rank > Students.getTotalStudentNumberRefer()) {
					throwError(INVAILD_INPUT, "Find Student", argv[4]);
				}
				int From0Rank = Rank - 1;
				Students.print(From0Rank);
			}
			else {
				throwError(INVAILD_INPUT, "Find Student", string("No Matching Argv"));
			}
		}
		else if (!MY_strcmp("lesson", argv[2])) {
			if (!MY_strcmp("-w", argv[3], false)) {
				if (CurrentSelect.Selected == false) {
					throwError(NOT_HAVE_SELECTED, "Find Lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
				}
				Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
				Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
				int Week = atoi(argv[4]);//Attention
				vector<int> LessonRanks;
				for (int i = 0; i < Point2Term->getNumberOfLessonRefer(); i++) {
					int n = Point2Term->Find(Week, argv[3], i);
					if (n != NOT_FOUND_LESSON) {
						LessonRanks.push_back(n);
						i = n;
					}
				}
				//大概没有一节课一天上两次吧
				for (auto j : LessonRanks) {
					if (LessonRanks[j] > Point2Term->getNumberOfLessonRefer() || LessonRanks[j] < 0)
						continue;
					Point2Term->print(LessonRanks[j]);
				}
			}
			else if (!MY_strcmp("-n", argv[3], false)) {
				if (CurrentSelect.Selected == false) {
					throwError(NOT_HAVE_SELECTED, "Find Lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
				}
				Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
				Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
				string LessonName = string(argv[4]);//Attention
				int LessonRank = Point2Term->Find(LessonName);
				Point2Term->print(LessonRank);
			}
			else if (!MY_strcmp("-t", argv[3], false)) {
				if (CurrentSelect.Selected == false) {
					throwError(NOT_HAVE_SELECTED, "Find Lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
				}
				Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
				Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
				int Type = atoi(argv[4]);//Attention
				vector<int> LessonRanks;
				for (int i = 0; i < Point2Term->getNumberOfLessonRefer(); i++) {
					int n = Point2Term->Find(Type, argv[3], i);
					if (n != NOT_FOUND_LESSON) {
						LessonRanks.push_back(n);
						i = n;
					}
				}
				//大概没有一节课一天上两次吧
				for (auto j : LessonRanks) {
					if (LessonRanks[j] > Point2Term->getNumberOfLessonRefer() || LessonRanks[j] < 0)
						continue;
					Point2Term->print(LessonRanks[j]);
				}
			}
			else if (!MY_strcmp("-r", argv[3], false)) {
				if (CurrentSelect.Selected == false) {
					throwError(NOT_HAVE_SELECTED, "Find Lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
				}
				Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
				Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
				int LessonRank = atoi(argv[4]) - 1;//Attention
				if (LessonRank > Point2Term->getNumberOfLessonRefer() || LessonRank <= 0)
					throwError(INVAILD_SELECTION, "Find Lesson", argv[4]);
				Point2Term->print(LessonRank);
			}
			else {
				throwError(INVAILD_INPUT, "Find Lesson", string("No Matching Argv"));
			}
		}
		else if (!MY_strcmp("rank", argv[2])) {
			int n = atoi(argv[3]);
			int StudentId;
			if (n <= 0 || n > Students.getTotalStudentNumberRefer()) {
				throwError(INVAILD_INPUT, "Select Student", argv[3]);
			}
			if (!(StudentId = (Students.getStudentHandle(n - 1)->getStudentId()))) {
				throwError(INVAILD_SELECTION, "Select Student", argv[3]);
			}
			Students.Find(StudentId);
		}
		else {
			throwError(INVAILD_INPUT, "Deletion", argv[2]);
		}
	}
    return 0;
}
int origin::sort(int argc, char *argv[])
{
	if (argc <= 3) {
		help({ "sort" });
	}
	if (argc == 4 || argc==5) {
		if (!MY_strcmp("student", argv[2])) {
			if (!MY_strcmp("-i", argv[3], false)) {
				if (argc == 5) {
					if (!strcasecmp(argv[4], "0"))
						Students.sort("-i", true);
					else if (!strcasecmp(argv[4], "1"))
						Students.sort("-i", false);
				}
				Students.sort("-i",true);
			}
			else if (!MY_strcmp("-n", argv[3], false)) {
				if (argc == 5) {
					if (!strcasecmp(argv[4], "0"))
						Students.sort("-n", true);
					else if (!strcasecmp(argv[4], "1"))
						Students.sort("-n", false);
				}
				Students.sort("-n", true);
			}
			else if (!MY_strcmp("-r", argv[3], false)) {

			}
			else {
				throwError(INVAILD_INPUT, "Sort Student", string("No Matching Argv"));
			}
		}
		else if (!MY_strcmp("lesson", argv[2])) {
			if (CurrentSelect.Selected == false) {
				throwError(NOT_HAVE_SELECTED, "sort lesson", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
			}
			Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
			Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
			if (!MY_strcmp("-w", argv[3], false)) {
				if (argc == 5) {
					if (!strcasecmp(argv[4], "0"))
						Point2Term->sort("-w", true);
					else if (!strcasecmp(argv[4], "1"))
						Point2Term->sort("-w", false);
				}
				Point2Term->sort("-w", true);

			}
			else if (!MY_strcmp("-n", argv[3], false)) {
				if (argc == 5) {
				if (!strcasecmp(argv[4], "0"))
					Point2Term->sort("-n", true);
				else if (!strcasecmp(argv[4], "1"))
					Point2Term->sort("-n", false);
			}
			Point2Term->sort("-n", true);

			}
			else if (!MY_strcmp("-t", argv[3], false)) {
				if (argc == 5) {
				if (!strcasecmp(argv[4], "0"))
					Point2Term->sort("-t", true);
				else if (!strcasecmp(argv[4], "1"))
					Point2Term->sort("-t", false);
			}
			Point2Term->sort("-t", true);

			}
			else {
				throwError(INVAILD_INPUT, "Sort Student", string("No Matching Argv"));
			}
		}
		else {
			throwError(INVAILD_INPUT, "Deletion", argv[2]);
		}
	}
    return 0;
}
int origin::print(int argc, char *argv[])
{
    if(argc<=2){
        help({"print"});
    }
    int i=2;
    if(argc==3){
        if(!MY_strcmp("student",argv[i])){
            Students.print();
        }
        else if(!MY_strcmp("term",argv[i])){
            if(CurrentSelect.Selected==false){
                throwError(NOT_HAVE_SELECTED,"Print Term",string("Now You Have Selected Student ")+string(to_string(CurrentSelect.StudentId))+string(" Year ")+string(to_string(CurrentSelect.CurrentYear))+string(" Term ")+string(to_string(CurrentSelect.CurrentTerm)));
            }
            Student* Point2Student=Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
            Point2Student->print();
        }
        else if(!MY_strcmp("lesson",argv[i])){
            if(CurrentSelect.Selected==false){
                throwError(NOT_HAVE_SELECTED,"Print Lesson",string("Now You Have Selected Student ")+string(to_string(CurrentSelect.StudentId))+string(" Year ")+string(to_string(CurrentSelect.CurrentYear))+string(" Term ")+string(to_string(CurrentSelect.CurrentTerm)));
            }
            Student* Point2Student=Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
            Term* Point2Term=Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear,CurrentSelect.CurrentTerm));
            Point2Term->print();
        }
        else{
            throwError(INVAILD_INPUT,"Addition",argv[i]);
        }
    }
    return 0;
}

int promote()
{
    if(!CurrentSelect.Selected)
       cout << "NS > ";
    else 
       cout <<CurrentSelect.StudentId<<"@"<<CurrentSelect.CurrentYear<<"T"<<CurrentSelect.CurrentTerm<<" > "; 
    return 0;
}

int promote(string Content)
{
	cout << Content << " > ";
	return 0;
}

unsigned readline_compatible::add(const std::vector<std::string>& input)
{
	//Init Command stack
	char *iargv[MAX_COMMAND];
	for (int i = 0; i<MAX_COMMAND; i++) {
		iargv[i] = new char[MAX_COMMAND_CHAR];
		memset(iargv[i], 0, sizeof(char)*MAX_COMMAND_CHAR);
	}
	for (int i = 1; i<=input.size(); i++)
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i-1].c_str());
	return origin::add(input.size() + 1, iargv);
}

unsigned readline_compatible::del(const std::vector<std::string>& input)
{
	//Init Command stack
	char *iargv[MAX_COMMAND];
	for (int i = 0; i<MAX_COMMAND; i++) {
		iargv[i] = new char[MAX_COMMAND_CHAR];
		memset(iargv[i], 0, sizeof(char)*MAX_COMMAND_CHAR);
	}
	for (int i = 1; i <= input.size(); i++)
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i-1].c_str());
	return origin::del(input.size() + 1, iargv);
}

unsigned readline_compatible::select(const std::vector<std::string>& input)
{
	//Init Command stack
	char *iargv[MAX_COMMAND];
	for (int i = 0; i<MAX_COMMAND; i++) {
		iargv[i] = new char[MAX_COMMAND_CHAR];
		memset(iargv[i], 0, sizeof(char)*MAX_COMMAND_CHAR);
	}
	for (int i = 1; i <= input.size(); i++)
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i-1].c_str());
	return origin::select(input.size() + 1, iargv);
}

unsigned readline_compatible::find(const std::vector<std::string>& input)
{
	//Init Command stack
	char *iargv[MAX_COMMAND];
	for (int i = 0; i<MAX_COMMAND; i++) {
		iargv[i] = new char[MAX_COMMAND_CHAR];
		memset(iargv[i], 0, sizeof(char)*MAX_COMMAND_CHAR);
	}
	for (int i = 1; i <= input.size(); i++)
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i-1].c_str());
	return origin::find(input.size() + 1, iargv);
}

unsigned readline_compatible::print(const std::vector<std::string>& input)
{
	//Init Command stack
	char *iargv[MAX_COMMAND];
	for (int i = 0; i<MAX_COMMAND; i++) {
		iargv[i] = new char[MAX_COMMAND_CHAR];
		memset(iargv[i], 0, sizeof(char)*MAX_COMMAND_CHAR);
	}
	for (int i = 1; i <= input.size(); i++)
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i-1].c_str());
	return origin::print(input.size() + 1, iargv);
}

unsigned readline_compatible::sort(const std::vector<std::string>& input)
{
	//Init Command stack
	char *iargv[MAX_COMMAND];
	for (int i = 0; i<MAX_COMMAND; i++) {
		iargv[i] = new char[MAX_COMMAND_CHAR];
		memset(iargv[i], 0, sizeof(char)*MAX_COMMAND_CHAR);
	}
	for (int i = 1; i <= input.size(); i++)
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i-1].c_str());
	return origin::sort(input.size() + 1, iargv);
}
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
unsigned readline_compatible::load(const std::vector<std::string>& input)
{
	if (CurrentSelect.StudentId == 0) {
		throwError(NOT_HAVE_SELECTED, "Load Lessons", "You have to at least select Student");
	}
	js::Reader Reader;
	js::Value Root;
	ifstream is;
	is.open(input[1], ios::binary);
	string line;
	while (getline(is, line)) {
		stringstream ss(line);
		Lesson temp;
		if (Reader.parse(ss, Root)) {
			temp.TeacherName = Root["teacherName"].asString();
			temp.Name = Root["courseName"].asString();
			temp.Type = 1 + Root["lessonType"].asInt();
			temp.Year = atoi(Root["year"].asString().c_str());
			temp.Term = Root["term"].asInt();
			temp.WeekTimes = Root["WeekTimes"].asInt();
			temp.Credit = atoi(Root["credit"].asString().c_str());
			string Week_str = Root["Week"].asString();
			string Place_str = Root["Place"].asString();
			string StartTime_str = Root["StartTime"].asString();
			string EndTime_str = Root["EndTime"].asString();
			vector<string> Weeks = split(Week_str, '|');
			vector<string> Places = split(Place_str, '|');
			vector<string> StartTimes = split(StartTime_str, '|');
			vector<string> EndTiems = split(EndTime_str, '|');
			for (int i = 0; i < temp.WeekTimes; i++) {
				temp.Weekday[i] = atoi(Weeks[i+1].c_str());
				temp.Place[i] = Places[i+1];
				temp.StartTime[i] = atoi(StartTimes[i+1].c_str());
				temp.EndTime[i] = atoi(EndTiems[i+1].c_str());
			}
			if (Root["HasGrade"].asInt() != js::nullValue) {
				temp.Grade_Ori = Root["Grade_Ori"].asDouble();
				temp.Grade = (temp.Grade_Ori - 50) / 10.0;
				temp.Finished = true;
			}
			else {
				temp.Grade_Ori = 0;
				temp.Grade = 0;
				temp.Finished = false;
			}
			int StudentRank = Students.Find(CurrentSelect.StudentId, "-i");
			Student* Point2Student = Students.getStudentHandle(StudentRank);
			int TermRank = Point2Student->getNumberOfTerm(temp.Year, temp.Term);
			Term* Point2Term = Point2Student->getTermHandle(TermRank);
			Lesson* Point2Lesson = &Point2Term->Lessons[Point2Term->getNumberOfLessonRefer()];
			*Point2Lesson = temp;
			Point2Lesson->AttachObserver(Point2Student);
			Point2Lesson->AttachObserver(Point2Term);
			if (Point2Lesson->Finished) {
				Point2Lesson->UpdateScore();
			}
			//Point2Lesson->Finished = true;
			//Point2Lesson->Name = temp.Name;
			//Point2Lesson->Year = temp.Year;
			//Point2Lesson->Type = temp.Type;
			//Point2Lesson->Grade_Ori = 0;
			//Point2Lesson->TeacherName = temp.TeacherName;
			//Point2Lesson->Credit = temp.Credit;
			//Point2Lesson->WeekTimes = temp.WeekTimes;
			
			//for(int i=0;i<Point2Lesson->WeekTimes;i++){
			//	Point2Lesson->Weekday[i] = temp.Weekday[i];
			//	Point2Lesson->StartTime[i] = temp.StartTime[i];
			//	Point2Lesson->EndTime[i] = temp.EndTime[i];
			//	Point2Lesson->Place[i] = temp.Place[i];
			//}
			Point2Term->getNumberOfLessonRefer()++;
			Point2Term->LessonsChanged = true;
			Point2Student->TermsChanged = true;
		}
	}
	is.close();
}
unsigned readline_compatible::help(const std::vector<std::string>& argv) {
	bool found = true;
	auto beg = argv.begin();
	if (argv.size() == 1) {
		cout << "可用功能    " << "用法" << endl;
		cout << "select      " << "选择学生，学年，学期" << endl;
		cout << "add         " << "添加学生课程课程" << endl;
		cout << "get         " << "从教务处网站在线获取学生课程课程" << endl;
		cout << "print       " << "显示学生信息，各学期总体情况，各学期课程安排" << endl;
		cout << "delete      " << "删除学生或课程" << endl;
		cout << "sort        " << "对学生或课程进行排序" << endl;
		cout << "run         " << "执行批处理脚本" << endl;
		cout << "load        " << "后接json格式课程数据文件路径，加载课程数据" << endl;
		cout << "find        " << "搜索指定学生或课程" << endl;
		cout << "save        " << "保存当前学生信息到[StudentID].json" << endl;
	}
	else if (argv.size() == 2) {
		if (argv[1] == string("select")) {
			cout << "可用参数    " << "用法" << RESET << endl;
			cout << "student     " << "后接学生学号，如" << BOLDMAGENTA << "select student 15323032" << RESET << RESET << endl;
			cout << "year        " << "后接学年    ，如" << BOLDMAGENTA << "select year    2016" << RESET << RESET << endl;
			cout << "term        " << "后接学期    ，如" << BOLDMAGENTA << "select term    1" << RESET << RESET << endl;
			++beg;
		}
		else if(argv[1] == string("add")) {
			cout << "可用参数    " << "用法" << RESET << endl;
			cout << "student     " << "添加学生，执行后将提示输入姓名，学号，院系信息" << endl;
			cout << "student     " << "后接学号，姓名，直接添加学生" << BOLDMAGENTA << "add student 15323032 李新锐" << RESET << RESET << endl;
			cout << "lesson      " << "添加课程，执行后将提示输入课程信息"  << RESET << endl;
		}
		else if (argv[1] == string("print")) {
			cout << "可用参数    " << "用法" << RESET << endl;
			cout << "student     " << "显示全部学生信息" <<  endl;
			cout << "term        " << "显示学生全部学期信息" << endl;
			cout << "lesson      " << "显示当前学期课程信息" << RESET << endl;
		}
		else if (argv[1] == string("delete")) {
			cout << "可用参数    " << "用法" << RESET << endl;
			cout << "student     " << "后接学号，删除指定学号的学生" << BOLDMAGENTA << "delete student 15323032" << RESET << RESET << endl;
			cout << "lesson      " << "后接课程编号，删除指定课程" << RESET << endl;
			cout << "rank        " << "后接学生编号，删除指定学生" << endl;
		}
		else if (argv[1] == string("sort")) {
			cout << "可用参数    " << "用法" << RESET << endl;
			cout << "student     " << "后接排序依据和排序方式，对学生进行排序" << BOLDMAGENTA << "delete student 15323032" << RESET << RESET << endl;
			cout << "可用的排序方式有：" << "-n：根据姓名排序；-i：根据学号排序" << endl;
			cout << "可用的排序方式有：" << "0：升序；1：降序" << endl;
			cout << "lesson      " << "后接排序依据和排序方式，对课程进行排序" << RESET << endl;
			cout << "可用的排序方式有：" << "-n：根据课程名排序；-w：根据每周第一次课的星期数排序；-t：根据类型排序" << endl;
			cout << "可用的排序方式有：" << "0：升序；1：降序" << endl;
		}
		else if (argv[1] == string("find")) {
			cout << "可用参数    " << "用法" << RESET << endl;
			cout << "student     " << "后接搜索方式，搜索指定的学生" << BOLDMAGENTA << "delete student 15323032" << RESET << RESET << endl;
			cout << "可用的搜索依据有：" << "-n：根据姓名搜索；-i：根据学号搜索" << endl;
			cout << "lesson      " << "后接搜索方式，搜索指定的课程" << RESET << endl;
			cout << "可用的排序方式有：" << "-n：根据课程名搜索；-w：搜索每星期某天的课程；-t：根据类型搜索" << endl;
		}
		else if (argv[1] == string("delete")) {
			cout << "后接脚本文件的路径，运行指定脚本" << endl;
		}
		else if (argv[1] == string("load")){
			cout << "后接json格式课程数据文件路径，加载课程数据" << endl;
		}
		else if (argv[1] == string("save")) {
			cout << "保存当前学生信息到[StudentID].json" << endl;
		}
		else {
			found = false;
		}
	}
	if (!found) {
		cout << "在模块" << BOLDMAGENTA << (*(argv.begin())) << RESET << "中。";
		for (auto beg = argv.begin() + 1; beg != argv.end(); ++beg)
			cout << "没有找到" << BOLDMAGENTA << *beg << RESET ;
		cout << endl;
		return 0;
	}

}
unsigned readline_compatible::save(const std::vector<std::string>& input) {
	if (CurrentSelect.StudentId == 0) {
		throwError(NOT_HAVE_SELECTED, "Save Lessons", "You have to at least select Student");
	}
	js::Reader Reader;
	js::Value Root;
	js::FastWriter Writer;
	ofstream os;
	string filename = to_string(CurrentSelect.StudentId) + ".json";
	os.open(filename, ios::binary);
	int StudentRank = Students.Find(CurrentSelect.StudentId, "-i");
	Student* Point2Student = Students.getStudentHandle(StudentRank);
	for (int i = 1; i <= Point2Student->NumberOfTerm; i++) {
		Term* Point2Term = Point2Student->getTermHandle(i);
		for (int j = 0; j < Point2Term->getNumberOfLessonRefer(); j++) {
			Lesson temp = Point2Term->Lessons[j];
			Root["teacherName"] = temp.TeacherName;
			Root["courseName"] = temp.Name;
			Root["lessonType"] = temp.Type - 1;
			Root["year"] = temp.Year;
			Root["term"] = temp.Term;
			Root["WeekTimes"] = temp.WeekTimes;
			Root["credit"] = temp.Credit;
			string Week_str;
			string Place_str;
			string StartTime_str;
			string EndTime_str;
			for (int i = 0; i < temp.WeekTimes; i++) {

				Week_str += "|" + to_string(temp.Weekday[i]);
				Place_str += "|" + temp.Place[i];
				StartTime_str += "|" + to_string(temp.StartTime[i]);
				EndTime_str += "|" + to_string(temp.EndTime[i]);
			}
			Root["Week"] = Week_str;
			Root["Place"] = Place_str;
			Root["StartTime"] = StartTime_str;
			Root["EndTime"] = EndTime_str;
			if (temp.Finished) {
				Root["HasGrade"] = 1;
				Root["Grade_Ori"] = temp.Grade_Ori;
			}
			else {
				Root["HasGrade"] = js::nullValue;
				Root["Grade_Ori"] = 0;
			}
			string str_writer = Writer.write(Root);
			os << str_writer;
			os << endl;
		}
	}
	os.close();
}
unsigned readline_compatible::set(const std::vector<std::string>& input) {
	if (CurrentSelect.Selected == false) {
		throwError(NOT_HAVE_SELECTED, "set grade", string("Now You Have Selected Student ") + string(to_string(CurrentSelect.StudentId)) + string(" Year ") + string(to_string(CurrentSelect.CurrentYear)) + string(" Term ") + string(to_string(CurrentSelect.CurrentTerm)));
	}
	Student* Point2Student = Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
	Term* Point2Term = Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear, CurrentSelect.CurrentTerm));
	Point2Term->setGrade();
	Point2Student->TermsChanged = true;
}
unsigned readline_compatible::get(const std::vector<std::string>& input) {
	system("python crawler.py");
}

