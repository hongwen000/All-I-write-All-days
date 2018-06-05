#include <iostream>
using namespace std;
int n[1000][1000];
int w[1000][1000];
int n2[1000][1000];
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
bool isSym(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            if(n[i][j])
                if(!n[j][i])
                    return false;
        }
    }
    return true;
}
bool isSelf(int size) {
	for(int i = 0; i < size; ++i)
        if(!n[i][i])
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
void mul2(int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            n2[i][j] = 0;
            for (int k = 0; k < size; k++) {
                n2[i][j] = n2[i][j] || (n[i][k] && n[k][j]);
            }
        }
    }
}
int main()
{
	int N;
	cin >> N;
	while(N--) {
		int size;
		cin >> size;
		int tmp;
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < size; ++j) {
				cin >> tmp;
				n[i][j] = tmp;
			}
		}
        mul2(size);
        cout << size << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; j++) {
                std::cout << n2[i][j] << ' ';
            }
            cout << endl;
        }
	}
}
