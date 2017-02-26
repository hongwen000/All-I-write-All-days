#include <iostream>
#include <stack>
using namespace std;
int main(){
	stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	cout<<a.top()<<endl;
	a.pop();
	a.pop();
	a.pop();
	return 0;
}