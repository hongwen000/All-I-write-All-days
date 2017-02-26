#include "Lesson.h"
string Lesson::GetTime(int StartTime)
{
    int Hour=8+((StartTime-1)*55)/60;
    int Min=(StartTime-1)*55%60;
    return (to_string(Hour)+":"+to_string(Min));
}
Lesson::Lesson(){
    Term=1;
    Name="NS";
    Type=0;
    for(int i=0;i<MAX_WEEK_TIMES;i++){
    Weekday[i]=0;
    StartTime[i]=1;
    EndTime[i]=1;
    }
    EndWeek=1;
    StartWeek=1;
    Finished=false;
    Credit=1;
    Grade=0;
    WeekTimes=0;
}
int Lesson::init()
{
    string Input;
    int Result;
	bool OK = false;
    cout<<"请输入课程名"<<endl;
	promote("Input Lesson Name");
    cin>>Input;
    Name=Input;
	cout << "请输入课程类型：" << endl;
	cout << BOLDMAGENTA << "1  " << RESET << "公必";
	cout << BOLDMAGENTA << "  2  " << RESET << "专必" << endl;
	cout << BOLDMAGENTA << "3  " << RESET << "专选";
	cout << BOLDMAGENTA << "  4  " << RESET << "公选" << endl; 
	while (!OK) {
		promote("Input Lesson Type");
		cin >> Input;
		if (Input[0] >= '1'&&Input[0] <= '4') {
			Type = (Input[0] - '0');
			OK = true;
		}
		else
			throwWarning(INVAILD_INPUT, "Add Lesson Type", Input.c_str());
	}
	OK = false;
    cout<<"请输入课程学分"<<endl;
	promote("Input Lesson Credit");
    cin >>Credit;
    cout<<"请输入每周上课次数"<<endl;
	promote("Input Week Times Num");
    int i;
	while (!OK) {
		cin>>i;
		if(i>MAX_WEEK_TIMES)
			throwWarning(INVAILD_INPUT,"Add Lesson Week Times",to_string(i).c_str());
		else {
			WeekTimes=i;
			OK = true;
		}
	}
   
    while(i)
    {
		OK = false;
        if(WeekTimes>1)
            cout<<"请输入每周第"<<WeekTimes-i+1<<"次课的时间信息"<<endl;
        cout<<"请输入周几上课（用数字"<<BOLDMAGENTA<<"1"<<RESET<<"到"<<BOLDMAGENTA<<"7"<<RESET<<"表示）"<<endl;
		while (!OK) {
			promote("Input");
		cin>>Input;
		if (Input[0] >= '1'&&Input[0] <= '7') {
            Weekday[i-1]=(Input[0]-'0');
			OK = true;
		}
        else
            throwWarning(INVAILD_INPUT,"Add Lesson Weekday",Input.c_str());
		}
        cout<<"请输入第几节上课"<<endl;
		promote("Input");
		OK = false;
		while (!OK) {
			cin>>Result;
			if (Result >= 1 && Result <= 15) {
				StartTime[i - 1] = Result;
				OK = true;
			}
			else
				throwWarning(INVAILD_INPUT, "Add Lesson StartTime", to_string(Result).c_str());
		}
        cout<<"请输入第几节下课"<<endl;
		promote("Input");
		OK = false;
		while (!OK) {
		cin>>Result;
		if (Result >= 1 && Result <= 15) {
			EndTime[i - 1] = Result;
			OK = true;
		}
        else
            throwWarning(INVAILD_INPUT,"Add Lesson EndTime",to_string(Result).c_str());
		}
		cout << "请输入上课地点" << endl;
		promote("Input");
		cin >> Place[i-1];
		i--;
    }
	OK = false;
 //   cout <<"请输入课程开始周数"<<endl;
	//while (!OK) {
	//promote("Input");
	//cin>>Result;
	//if (Result >= 1 && Result <= 20) {
 //       StartWeek=Result;
	//	OK = true;
	//}
 //   else
 //       throwWarning(INVAILD_INPUT,"Add Lesson StartWeek",to_string(Result).c_str());
	//}
 //   cout <<"请输入课程结束周数"<<endl;
	//OK = false;
	//while (!OK) {
	//	promote("Input");
	//	cin >> Result;
	//	if (Result >= 1 && Result <= 20) {
	//		EndWeek = Result;
	//		OK = true;
	//	}
	//	else
	//		throwWarning(INVAILD_INPUT, "Add Lesson EndWeek", to_string(Result).c_str());
	//}
	cout<<"请输入老师名字"<<endl;
	promote("Input");
    cin>>Input;
    TeacherName=Input;

    return 0;
    }

string Lesson::getGrade()
{
	if (this->Grade == 0)
		return string("暂无");
	else {
		return to_string(this->Grade);
	}
	return 0;
}
