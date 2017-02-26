#ifndef BACKEDN_H
#define BACKEDN_H
#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
#define MAX_COMMAND 32//256
#define MAX_COMMAND_CHAR 256
#define MAX_STUDENTS_NUM 8//256
#define MAX_WEEK_TIMES 4
#define UTF8_CHINESE_BYTE 3
#define MAX_LENGTH_OF_MAJOR 10*UTF8_CHINESE_BYTE
#define MAX_LENGTH_OF_SCHOOL 11*UTF8_CHINESE_BYTE
#define INVAILD_INPUT 0x01
#define NOT_HAVE_SELECTED 0x02
#define ACCESS_VIOLATION 0x04
#define ACCESS_UNREASONABLE 0x08
#define STORAGE_FULL 0x0F
#define NOT_FOUND_LESSON 0x00
#define NOT_FOUND_STUDENTID 0x00
#define INVAILD_SELECTION -1
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define MAX_LESSON_OF_TERM 16//128
#define MAX_TERM_OF_STUDENT 16//32
#define DURATION_OF_LESSON 45
#ifdef _MSC_VER
static const char *ZH_CN_LOCALE_STRING = "Chinese_china";
#else
static const char *ZH_CN_LOCALE_STRING = "zh_CN.utf8";
#endif
bool zh_CN_less_than(const string &s1, const string &s2);
char* strcpy_s(char *dest,size_t destsz, const char *src);
namespace origin {
	int select(int argc, char *argv[]);
	int add(int argc, char *argv[]);
	int del(int argc, char *argv[]);
	int find(int argc, char *argv[]);
	int print(int argc, char *argv[]);
	int sort(int argc, char *argv[]);
}
namespace readline_compatible {
	unsigned add(const std::vector<std::string> & input);
	unsigned del(const std::vector<std::string> & input);
	unsigned select(const std::vector<std::string> & input);
	unsigned find(const std::vector<std::string> & input);
	unsigned print(const std::vector<std::string> & input);
	unsigned sort(const std::vector<std::string> & input);
}

int promote();
int promote(string Content);
int vaildStudentId(const char InputStudentId[]);
int vaildTerm(const char InputTerm[]);
int vaildYear(const char InputYear[]);
int MY_strcmp(const char *Command, const char *Input, bool EnableShort=true);
void throwError(int ErrorLevel,string ErrorProcedure, string ErrorMessage);
void throwError(int ErrorLevel,string ErrorProcedure, const char *agrv);
void throwWarning(int ErrorLevel, string ErrorProcedure,const char *argv,string ErrorMessage="");
extern string Weekdays[7];
extern string LessonType[4];
typedef struct Error_Struct{
    int ErrorLevel;
    char ErrorArgv[MAX_COMMAND_CHAR];
    string ErrorProcedure;
    string ErrorMessage;
}Error;
typedef struct Selection_Struct{
    bool Selected=false;
    int StudentId=0;
    int CurrentYear=0;
    int CurrentTerm=0;
}Selection;
class Time{
    public:
    int Year;
    int Month;
    int Day;
    int Hour;
    int Min;
    int Second;
    Time()
    {
    reNew();
    }
    void reNew()
    {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y");
    Year=atoi((ss.str()).c_str());
    ss.sync();
    ss << std::put_time(std::localtime(&in_time_t), "%m");
    Month=atoi((ss.str()).c_str());
    ss.sync();
    ss << std::put_time(std::localtime(&in_time_t), "%d");
    Day=atoi((ss.str()).c_str());
    ss.sync();
    ss << std::put_time(std::localtime(&in_time_t), "%H");
    Hour=atoi((ss.str()).c_str());
    ss.sync();
    ss << std::put_time(std::localtime(&in_time_t), "%M");
    Min=atoi((ss.str()).c_str());
    ss.sync();
    ss << std::put_time(std::localtime(&in_time_t), "%S");
    Second=atoi((ss.str()).c_str());
    ss.sync();
    }
    int getYear()
    {
        return Year;
    }
    int getMonth()
    {
        return Month;
    }
    int getDay()
    {
        return Day;
    }
    int getHour()
    {
        return Hour;
    }
    int getMin()
    {
        return Min;
    }
    int getSecond()
    {
        return Second;
    }
};

extern Selection CurrentSelect;
extern string Path;
extern string FileNamePath;
extern string StudentListFilePath;
#endif
