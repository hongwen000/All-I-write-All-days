#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <locale>
using namespace std;

int main()
{
	locale loc("");
	cout << loc.name().c_str()<<endl;
    map<string,int> word_map;
	wstring word;
	wchar_t word_in;
	wifstream f;
	f.open("text.txt");
	f.imbue(loc);
    while (!f.eof()) {
		f.get(word_in);
		word = word_in;
		wcout.imbue(loc);
        wcout << word_in <<endl;
		//++word_map[word];                      
    }  
    for (auto iter = word_map.begin(); iter != word_map.end(); ++iter)
        cout << iter->first << " : " << iter->second << endl;
    return 0;
}