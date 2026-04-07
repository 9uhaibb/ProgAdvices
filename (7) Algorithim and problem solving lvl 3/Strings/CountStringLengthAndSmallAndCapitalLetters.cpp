// Read String then count string length and small and capital letters in that string
/*F : 1-Read string. 2-/-3 count Small/Capital letters*/

#include<iostream>
#include<string>
#include"StringCharLib.h"

using namespace std;

enum enLetterCount {SmallLetter = 0, CapitalLetter = 1};
// method 1
int CountLetters (string String, enLetterCount LetterCount)
{
    short Counter = 0;
    for (int i = 0; i < String.length(); i++)
    {
        if (LetterCount == enLetterCount::CapitalLetter && isupper(String[i]))
            ;
        {
            Counter++;
        }
        if (LetterCount == enLetterCount::SmallLetter && islower(String[i]))
        {
            Counter++;
        }
    }
    return Counter;
}

// method 2
int CountSmallLettersInString (string String1)
{
    int SCounter = 0;
    for (int i = 0; i < String1.length(); i++)
    {
        if (islower(String1[i]))
        {
            SCounter++;
        }
    }
    return SCounter;
}
int CountCapitalLettersInString (string String1)
{
        int CCounter = 0;
    for (int i = 0; i < String1.length(); i++)
    {
        if (isupper(String1[i]))
        {
            CCounter++;
        }
    }
    return CCounter;
}

int main ()
{
    string S1 = StringCharLib::ReadString();

    cout << "\nString Length = " << S1.length() << endl;
    cout << "Capital Letters Count = " << CountLetters(S1, enLetterCount::CapitalLetter) << endl;
    cout << "Small Letters Count = " << CountLetters(S1, enLetterCount::SmallLetter) << endl;

    system ("pause>0");
}