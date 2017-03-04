#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;
using line_no = vector<std::string>::size_type;

class QueryResult;

class TextQuery {
    public:
        TextQuery(ifstream&);
        QueryResult query(const string&) const;
    private:
        shared_ptr<vector<string>> file;
        map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
};

ostream& printResult(ofstream, const QueryResult&);
class QueryResult {
    public:
        QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
            sought(s), lines(p), file(f) { }
        string sought;
        shared_ptr<set<line_no>> lines;
        shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}


string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;
}

ostream& printResult(ostream& os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << endl;
    return os;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        cout << " enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        printResult(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream file("expalme.txt");
    runQueries(file);
    return 0;
}
