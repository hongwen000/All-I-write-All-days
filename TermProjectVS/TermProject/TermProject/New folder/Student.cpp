#include "Student.h"
void Student::calcTermTillNow()
{
 Time CurrentTime;
 this->NumberOfTerm= getNumberOfTerm(CurrentTime.getYear(),(CurrentTime.getMonth()<9&&CurrentTime.getMonth()>=3)?2:1); 
}
int Student::getOverallCredit()
{
    reNewStudentContentAfterTermsChanged();
    return OverallCredit;
}
int Student::getOverallGrade()
{
    reNewStudentContentAfterTermsChanged();
    return OverallGrade;
}
int Student::getOverallGradeExpectPubEle()
{
    reNewStudentContentAfterTermsChanged();
    return OverallGradeExpectPubEle;
}
int Student::getOverallCreditExpectPubEle()
{
    reNewStudentContentAfterTermsChanged();
    return OverallCreditExpectPubEle;
}
Student::Student(){
    Name="N/S";
    StudentId=-1;
    EntranceYear=1924;
    OverallGrade=-1;
    OverallCredit=0;
    TermsChanged=false;
    NumberOfTerm=0;
}
const Term& Student::getTerm(int n)
{
    char argv[MAX_COMMAND_CHAR];
    sprintf(argv,"%d",n);
    if(n>MAX_TERM_OF_STUDENT)
        throwError(ACCESS_VIOLATION,"Read Terms",argv);
    return Terms[n];
}
const Term& Student::operator [](int n)
{
    char argv[MAX_COMMAND_CHAR];
    sprintf(argv,"%d",n);
    if(n>MAX_TERM_OF_STUDENT)
        throwError(ACCESS_VIOLATION,"Read Terms",argv);
    return Terms[n];
}
void Student::calcEntranceYear()
{
    EntranceYear=2000+StudentId/1000000;
}
int Student::getNumberOfTerm(int Year, int Term)
{
    Time CurrentTime;
    char argv[MAX_COMMAND_CHAR];
    sprintf(argv,"%d",Year);
    argv[4]=',';
    sprintf(argv,"%d",Term);
    if(Year>CurrentTime.getYear())
        throwWarning(ACCESS_UNREASONABLE,"Read Terms",argv);
    int Part1=(Year-EntranceYear)*3+Term;
    int Part2=(EntranceYear<=2015?(2015-EntranceYear+1):0);                              
    int Part3=((Year-(EntranceYear<=2015?2016:EntranceYear))*2+Term);
    return (Year<=2015?Part1:(Part2*3+Part3));/*
    return (((Year<=2015?((Year-EntranceYear)*3+Term):
(((EntranceYear<=2015?(2015-EntranceYear+1):0)*3+
\(Year-(EntranceYear<=2015?2016:EntranceYear)*2+Term))); 
*/
}
Term* Student::getTermHandle(int n)
{
    char argv[MAX_COMMAND_CHAR];
    sprintf(argv,"%d",n);
    if(n>MAX_TERM_OF_STUDENT)
        throwError(ACCESS_VIOLATION,"Write Terms",argv);
    return &Terms[n];
}
int Student::setName(string Name)
{
    this->Name=Name;
    return 0;
}
int Student::getTotalTermOfYear(int Year)
{
    return Year<=2015?3:2;
}
int Student::setStudentId(int StudentId)
{
    Time CurrentTime;
    this->StudentId=StudentId;
    this->calcEntranceYear();
    this->calcTermTillNow();
    for(int i=EntranceYear;i<=CurrentTime.getYear();i++)
    {
        for(int j=1;j<=getTotalTermOfYear(i);j++)
        {
        int TotalRank=getNumberOfTerm(i,j);
		this->getTermHandle(TotalRank)->TermRankOfLastTerm = getNumberOfTerm(CurrentTime.getYear(), (CurrentTime.getMonth() >= 3 || CurrentTime.getMonth() < 9 ? 2 : 1));
        this->getTermHandle(TotalRank)->setYear(i);
        this->getTermHandle(TotalRank)->setTotalRank(TotalRank);
        this->getTermHandle(TotalRank)->setRank(j);
        }
    }
    return 0;
}
string Student::getName()
{
    return this->Name;
}
int Student::getStudentId()
{
    return this->StudentId;
}
void Student::reNewStudentContentAfterTermsChanged()
{
    if(TermsChanged)
    {
        int SumOfCredit=0;
        int SumOfGrade=0;
        int SumOfCreditExpectPubEle=0;
        int SumOfGradeExpectPubEle=0;
        for(int i=0;i<NumberOfTerm;i++)
        {
            SumOfCredit+=Terms[i].getCredit();
            SumOfGrade+=Terms[i].getCredit()*Terms[i].getAverage();
            SumOfCreditExpectPubEle=Terms[i].getCreditExpectPubEle();
            SumOfGradeExpectPubEle+=Terms[i].getCreditExpectPubEle()*Terms[i].getAverageExpectPubEle();
        }
        this->OverallCredit=SumOfCredit;
        this->OverallGrade=SumOfGrade/SumOfCredit;
        this->OverallCreditExpectPubEle=SumOfCreditExpectPubEle;
        this->OverallGradeExpectPubEle=SumOfGradeExpectPubEle/SumOfCreditExpectPubEle;
        this->TermsChanged=false;
    }
}
string Student::getSchool()
{
    return this->School;
}
string Student::getMajor()
{
    return this->Major;
}
int Student::setSchool(string School)
{
    this->School=School;
    return 0;
}
int Student::setMajor(string Major)
{
    bool OK=false;
    while(!OK)
    {
        if(School.size()>MAX_LENGTH_OF_MAJOR)
        {
            throwWarning(INVAILD_INPUT,"Set Major Name",Major.c_str(),"Please Input a Shorter Major Name");
            cin>>Major;
            continue;
        }
        else
            OK=true;
        this->Major=Major;
    }
    return 0;
}

int Student::print()
{
    cout <<CYAN<<"  序号"<<"  学年     "<<"  学期"<<"  已选课程"<<"  学分"<<"  平均绩点"<<"  公选外绩点"<<RESET<<endl;
//  cout <<CYAN<<"  256 "<<"  2015-2016"<<"  1   "<<"  11门    "<<"  27  "<<"  4.35    "<<"  4.55      "
          cout <<"  ----"<<"  ---------"<<"  ----"<<"  --------"<<"  ----"<<"  --------" << "  ----------" <<endl;
    Time CurrentTime;
    for(int i=EntranceYear;i<=CurrentTime.getYear();i++)
    {
        for(int j=1;j<=getTotalTermOfYear(i);j++)
        {
        int TotalRank=getNumberOfTerm(i,j);
        cout<<setfill(' ') << "  " <<setw(4)<<TotalRank << "  " <<i<<"-"<<i+1<<setw(6)<<j<<setw(10)<<Terms[TotalRank].getNumberOfLessonRefer();
        cout<<"  "<<setw(4)<<Terms[TotalRank].getCredit()<<setw(10)<<Terms[TotalRank].getAverage()<<setw(12)<<Terms[TotalRank].getAverageExpectPubEle()<<RESET<<endl;
        }
    }
    return 0;
}

