#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
string encode(string& str, vector<int> key) {
    for(size_t i = 0; i < key.size(); ++i) key[i] -= 1;
    string ret;
    vector<vector<char> > M;
    int column = key.size();
    int row = ceil(str.size() / (double)column);
    int cnt = 0;
    for(int i = 0; i < row; ++i) {
        vector<char> r(column);
        for(int i = 0; i < column; ++i) r[i] = 'X';
        for(int j = 0; j < column; ++j) {
            size_t pos = column * i + j;
            if(pos < str.size())
                r[key[j]] = str.at(cnt++);
            else break;
        }
        M.push_back(r);
    }
    for(int j = 0; j < column; ++j) {
        for(int i = 0; i < row; ++i) {
            ret += M[i][j];
        }
        ret += ' ';
    }
    return ret;
}

string decode(string& str, vector<int> key) {
    for(size_t i = 0; i < key.size(); ++i) key[i] -= 1;
    string ret;
    vector<vector<char> > M;
    int column = key.size();
    int fullrow = str.size() / column;
    int row = ceil(str.size() / (double)column);
    //int more = str.size() - fullrow * column;
    for(int i = 0; i < row; ++i) {
        vector<char> r(column);
        for(int j = 0; j < column; ++j) {
            r[j] = 'X';
        }
        M.push_back(r);
    }

    int cnt = 0;
    for(int i = 0; i < column; ++i) {
        for(int j = 0; j < row; ++j) {
            M[j][i] = str.at(cnt++);
        }
    }
    cout << "###" << endl;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "###" << endl;
    vector<vector<char> > B;
    for(int i = 0; i < row; ++i) {
        vector<char> r(column);
        for(int j = 0; j < column; ++j) {
            r[j] = '\0';
        }
        B.push_back(r);
    }
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) {
            int k = 0;
            for(; k < column; ++k) {
                if(key[k] == j) break;
            }
            B[i][k] = M[i][j];
        }
    }
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) {
            if(B[i][j] != '\0')
                ret += B[i][j];
        }
    }
    return ret;
}

string filter(const string& s) {
    char* filtered = new char[s.size() + 1];
    int cnt = 0;
    for(size_t i = 0; i < s.size(); ++i) {
        char ch = s.at(i);
        if(ch != ' ' && ch != ',' && ch != '.')
            filtered[cnt++] = ch;
    }
    filtered[cnt] = '\0';
    string ret(filtered);
    delete[] filtered;
    return ret;
}

int main() {
    string ln;
    cout << "###Input key" << endl;
    getline(cin, ln);
    string sortedln = ln;
    std::sort(sortedln.begin(), sortedln.end());
    map<char, int> mpp;
    for(size_t i = 0; i < sortedln.size(); ++i)
    {
        mpp[sortedln.at(i)] = i + 1;
    }
    vector<int> key;
    for(size_t i = 0; i < ln.size(); ++i)
    {
        key.push_back(mpp[ln.at(i)]);
//        mpp[sortedln.at(i)] = i + 1;
    }
    cout << "###";
    for(auto i : key) cout << i << ' ';
    cout << endl;
//    getline(cin, ln);
//    size_t p1 = 0;
 //   size_t p2 = 0;
//    for(; p1 <= ln.size(); ++p1) {
//        if(p1 == ln.size() || ln.at(p1) == ' ') {
//            string s = ln.substr(p2, p1 - p2);
//            if(!s.empty() && s != " ")
//                key.push_back(stoi(ln.substr(p2, p1 - p2)));
//            p2 = p1;
//        }
//    }
    cout << "###Input String" << endl;
    getline(cin, ln);
    cout << "###" << filter(ln) << endl;
    ln = filter(ln);
//    cin >> ln;
    bool flag;
    cout << "###Encode(0) or decode(1)?" << endl;
    cin >> flag;
    if(flag) {
        cout << decode(ln, key) << endl;
    } else {
        cout << encode(ln, key) << endl;
    }
}
