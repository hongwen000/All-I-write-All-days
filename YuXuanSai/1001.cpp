#include <string>
#include <iostream>
using namespace std;
int main()
{
	string case1, case2;
	cin >> case1;
	cin >> case2;
	int i = 0;
	for(i = 0; i<case1.size(); i++){
		if(case1.at(i) != '0'){
				break;
		}
	}
	case1 = case1.substr(i);
	i = 0;
	for(i = 0; i<case2.size(); i++){
		if(case2.at(i) != '0'){
				break;
		}
	}
	case2 = case2.substr(i);
	if(case1.length()>case2.length())
		cout << ">"<<endl;
	else if(case1.length()==case2.length()){
		if(case1>case2)
			cout << ">"<<endl;
		else if(case1 == case2)
			cout << "=" <<endl;
		else
			cout << "<" <<endl;
		}
	else
		cout << "<"<<endl;
	return 0;
}