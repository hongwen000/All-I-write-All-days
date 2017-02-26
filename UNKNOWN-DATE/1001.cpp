// Problem#: 1001
// Submission#: 4891211
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;
int check_case(string code)
{
    if(code.length()==1 || code.length()==0)
        return 5;
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
        if(code=="0")
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
                                string first2code=code.substr(i-2,2);
                                int case_now=check_case(first2code);
                                switch (case_now)
                                {
                                        case 1:
                                        {
                                                status[i]=status[i-2];//right
                                                break;
                                        }
                                        case 2:
                                        {
                                                status[i]=status[i-1];
                                                break;
                                        }
                                        case 3:
                                        {
                                                status[i]=status[i-1]+status[i-2];//wrong ,no + 1
                                                break;
                                        }
                                        case 4:
                                        {
                                                status[i]=status[i-1]; //wrong max(status[i-1],status[i-2])
                                                break;
                                        }
                    case 5:
                    {
                        status[i]=status[i-1];
                    }
                                        default: break;
                                }
                        }
                        answer=status[dits];
                cout <<answer<<endl;
    }
    return 0;
}                                 