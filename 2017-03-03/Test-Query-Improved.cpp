#include "Test-Query-Improved.h"
void runQueries(ifstream &infile)
{
    Query qand = Query("one") & Query("by"); 
    Query qnot = ~Query("one");
    TextQuery tq(infile);
    printResult(cout, qand.eval(tq)) << endl;
    printResult(cout, qnot.eval(tq)) << endl;
}

int main()
{
    ifstream file("example.txt");
    runQueries(file);
    return 0;
}

