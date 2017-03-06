#include <iostream>
#inclde <algorithm>
using namespace std;
int check_case(string code)
{
    int last_num=(code.at(1))-48;
    int penult_num=(code.at(0))-48;
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
int main()
{
    while(1)
    {
		string code;
        cin >>code;
		int dits=code.length();
		int status[dits+1];
		int answer;
        if(code==0)
            return 0;
        if(dits==1)
            answer =1;
        else
			status[0]=1;
			status[1]=1;
			string first2code=code.substr(0,2);
			int case_first2code=check_case(first2code);
			if(case_first2code==3)
				status[2]=2;
			else
				status[2]=1;
			for(int i=3;i<=dits+1;i++)
			{
				string first2code=code.substr(i-1,2);
				int case_now=check_case(first2code);
				switch (case_now)
				{
					case 1:
					{
						status[i]=status[i-2];
						break;
					}
					case 2:
					{
						status[i]=status[i-1];
						break;
					}
					case 3:
					{
						status[i]=status[i-1]+status[i-2]+1;
						break;
					}
					case 4:
					{
						status[i]=max(status[i-1],status[i-2]);
						break;
					}
					default: break;
				}
			}
			answer=status[dits];
		cout <<answer<<endl;
    }
    return 0;
}
