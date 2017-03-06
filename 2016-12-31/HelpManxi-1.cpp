#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    map<string,int> word_map;
	string word;
	char word_in[6];
	ifstream f;
	f.open("text.txt");
    while (!f.eof()) {
		f.get(word_in, 4, '\n');
		word = word_in;
        ++word_map[word];                      
    }  
    for (auto iter = word_map.begin(); iter != word_map.end(); ++iter)
        cout << iter->first << " : " << iter->second << endl;
    return 0;
}