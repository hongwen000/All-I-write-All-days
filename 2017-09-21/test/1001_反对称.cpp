#include <iostream>
using namespace std;
int n[1000][1000];
int w[1000][1000];
bool isReSym(int size) {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(i == j)
				continue;
			else {
				if(n[i][j] && n[j][i])
					return false;
			}
		}
	}
	return true;
}
bool isSelf(int size) {
	for(int i = 0; i < size; ++i)
		if(n[i][i] == 0)
			return false;
	return true;
}
bool isTrans(int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            w[i][j] = n[i][j];
    for(int k = 0; k < size; ++k)
        for(int i = 0; i < size; ++i)
           for(int j = 0; j < size; ++j)
              w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            if(w[i][j] != n[i][j])
                return false;
    return true;
}
void mul(int size) {
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size; ++j) {
                for(int k = 0; k < size; ++k)
                    w[i][j] = w[i][j] || (n[k][j] && n[i][k]);
			}
		}
}
int main()
{
	int N;
	cin >> N;
	while(N--) {
        for(int i = 0; i < 1000; ++i)
            for(int j = 0; j < 1000; ++j)
                w[i][j] = 0;
		int size;
		cin >> size;
		int tmp;
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size; ++j) {
				cin >> tmp;
				n[i][j] = tmp;
			}
		}
        mul(size);
        cout << size << endl;
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size; ++j) {
				cout << w[i][j] << ' ';
			}
            cout << endl;
		}
       cout << endl;
	}
}
