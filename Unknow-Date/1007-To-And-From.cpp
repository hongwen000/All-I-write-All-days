#include <iostream>
#include <string>
using namespace std;

void Creat_Rect_Array(const string Orig_String, char(&Answer_String)[20][200], int Column, int Number_Of_Line);
void Print_Answer(char Answer_String[20][200], int Column, int Number_Of_Line);
int main()
{
    int Column(1);
    char Answer_String[20][200];
    string Orig_String;
    cin >> Column;
    while (Column != 0)
    {
        cin >> Orig_String;
        int Number_Of_Line = Orig_String.length() / Column;
        try {
            Creat_Rect_Array(Orig_String, Answer_String, Column, Number_Of_Line);
        }
        catch (int n) {
            cout << n << "不能被列数整除";
            break;
        }
        Print_Answer(Answer_String, Column, Number_Of_Line);
        cin >> Column;
    }
    return 0;
}

void Creat_Rect_Array(const string Orig_String, char(&Answer_String)[20][200], int Column, int Number_Of_Line)
{
    if ((Orig_String.length() - (Number_Of_Line*Column)) != 0)
    {
        throw Orig_String.length();
    }
    for (int i = 0; i < Number_Of_Line; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            if (i % 2 == 0)
            {
                Answer_String[i][j] = Orig_String.at(i*Column + j);
            }
            else
            {
                Answer_String[i][Column - j - 1] = Orig_String.at(i*Column + j);
            }
        }
    }
}

void Print_Answer(char Answer_String[20][200], int Column, int Number_Of_Line)
{
    bool Flag(1);
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Number_Of_Line; j++)
        {
            cout << Answer_String[j][i];
        }
    }
    cout << endl;
}             