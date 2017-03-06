#include <iostream>
#include <cstdio>
#define status1 1
using namespace std;
int check_case(string code)
{
    int last_num=(code.at(code.length()-1))-48;
    int penult_num=(code.at(code.length()-2))-48;
    int dit2_num=10*penult_num+last_num;
    if(penult_num==0)
    {
        return 2;
    }
    else if(dit2_num==10 || dit2_num==20)
    {
        return 1;
    }
    else if(dit2_num>26)
    {
        return 4;
    }
	else
	{
		return 3;
	}
}
int status(int status2, string code)
{
    if(code.length()==2)
        return status2;
    else if(code.length()==1)
        return 0;
    else
    {
        int case_now=check_case(code.substr(code.length()-2,2));
        if(case_now==1)
            return status(status2,code.substr(0,code.length()-2));
        else if(case_now==2)
            return status(status2,code.substr(0,code.length()-1));
        else if(case_now==3)
            return 1+status(status2,code.substr(0,code.length()-2))+status(status2,code.substr(0,code.length()-1));
		else//case_now=4
			return status(status2,code.substr(0,code.length()-2))+status(status2,code.substr(0,code.length()-1));
	}
}
int check_code(string code)
{
    int status2;
    int case_now=check_case(code.substr(0,2));
	if(case_now==3)
        status2=1;
    else//case_now=3 || 4
        status2=0;
    return 1+status(status2,code);
}
int main()
{
    string code;
    while(1)
    {
        cin >>code;
		int answer;
        if(code=="0")
            return 0;
        if(code.length()==1)
            answer =1;
        else
            answer=check_code(code);
        cout <<answer<<endl;
    }
    return 0;
}
