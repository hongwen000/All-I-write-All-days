#include "Storage.h"
#include <string>
#include <iostream>
using namespace std;
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
    int i=2;
    if(argc==3){
        if(!MY_strcmp("student",argv[i])){
            Students.Add();
        }
        else if(!MY_strcmp("lesson",argv[i])){
            if(CurrentSelect.Selected==false){
                throwError(NOT_HAVE_SELECTED,"add lesson",string("Now You Have Selected Student ")+string(to_string(CurrentSelect.StudentId))+string(" Year ")+string(to_string(CurrentSelect.CurrentYear))+string(" Term ")+string(to_string(CurrentSelect.CurrentTerm)));
            }
            Student* Point2Student=Students.getStudentHandle(Students.Find(CurrentSelect.StudentId));
            Term* Point2Term=Point2Student->getTermHandle(Point2Student->getNumberOfTerm(CurrentSelect.CurrentYear,CurrentSelect.CurrentTerm));
            Point2Term->Add();
        }
        else{
            throwError(INVAILD_INPUT,"Addition",argv[i]);
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
					LessonRanks.push_back(Point2Term->Find(Week, argv[3],i));
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
					LessonRanks.push_back(Point2Term->Find(Type, argv[3], i));
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
				throwError(INVAILD_INPUT, "Find Student", string("No Matching Argv"));
			}
		}
		else if (!MY_strcmp("lesson", argv[2])) {
			if (!MY_strcmp("-w", argv[3], false)) {

			}
			else if (!MY_strcmp("-n", argv[3], false)) {

			}
			else if (!MY_strcmp("-t", argv[3], false)) {

			}
			else if (!MY_strcmp("-r", argv[3], false)) {

			}
			else {

			}
		}
		else if (!MY_strcmp("rank", argv[2])) {

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
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i].c_str());
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
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i].c_str());
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
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i].c_str());
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
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i].c_str());
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
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i].c_str());
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
		strcpy_s(iargv[i], MAX_COMMAND_CHAR, input[i].c_str());
	return origin::sort(input.size() + 1, iargv);
}
