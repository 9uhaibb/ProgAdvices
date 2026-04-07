#include <iostream>
using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

int ReadMark () 
{
    int mark;
    cout << "Enter Your mark : ";
    cin >> mark;
    return mark;
}
enPassFail CheckMark (int mark)
{
    if (mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}
 void PrintMark (int mark) 
 {
    if (CheckMark (mark) == enPassFail::Pass)
        cout << "Pass.\n";
    else
        cout << "Fail.\n";
 }
int main () 
{
    PrintMark (ReadMark ());
}