#include <iostream>
#include <cmath>
#include <sys/time.h>
#define status1 1
using namespace std;
int check_case(long long int code)
{
    int last_num=code%10;
    int penult_num=(code/10)%10;
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
int status(int status2, long long int code, int dits)
{
    if(dits==2)
        return status2;
    else if(dits==1)
        return 0;
    else
    {
        int case_now=check_case(code);
        if(case_now==1)
            return status(status2,code/100,dits-2);
        else if(case_now==2)
            return status(status2,code/10,dits-1);
        else if(case_now==3)
            return 1+status(status2,code/100,dits-2)+status(status2,code/10,dits-1);
		else//case_now=4
			return status(status2,code/100,dits-2) +status(status2,code/10,dits-1);
	}
}
int check_code(long long int code,int dits)
{
    int status2;
    int case_now=check_case(code/pow(10,dits-2));
	if(case_now==3)
        status2=1;
    else//case_now=3 || 4
        status2=0;
    return 1+status(status2,code,dits);
}
int main()
{
	 long beginTime =clock();
    long long int code;
    while(1)
    {
        cin >>code;
		long long int temp=code;
		int dits=0;
		while(temp)
		{
			temp=temp/10;
			dits++;
		}
		int answer;
        if(code==0)
            return 0;
        if(dits==1)
            answer =1;
        else
            answer=check_code(code,dits);
        cout <<answer<<endl;
    }
	 long endTime=clock();
	cout<<endTime-beginTime<<endl;
    return 0;
}
