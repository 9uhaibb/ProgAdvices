// Read string and a character, then
// count the character in that string Match Case or not

/*F: 1- Read string, 2- Read Character
     3- count letter*/

#include<iostream>
#include<string>
#include"StringCharLib.h"

using namespace std;

int LetterCountInStringNotMatchCase (string String, char CharacterToCount, bool MatchCase = true)
/*Count Small/Capital and both*/
{
    int Counter = 0;
    for (int i = 0; i < String.length(); i++)
    {
        if(MatchCase)
        {
            if (String[i] == CharacterToCount)
            {
                Counter++;
            }
        }
        else
        {
            if (tolower(String[i]) == tolower(CharacterToCount))
            /*if they dosent match cuz one of them is small\ capital
            make them two small or capital */
            {
                Counter++;
            }
        }
    }
    return Counter;
}

int LetterCountInStringMatchCase/*Only Count Small/Capital but not both*/ (string String, char CharacterToCount)
{
    int Counter = 0;
    for (int i = 0; i < String.length(); i++)
    {
        if (String[i] == CharacterToCount)
        {
            Counter++;
        }
    }
    return Counter;
}


int main ()
{
    string S1 = StringCharLib::ReadString();
    char Ch1 = StringCharLib::ReadCharacter();

    cout << "Letter \'" << Ch1 << "\' Count = " << LetterCountInStringMatchCase(S1, Ch1) << endl;
    cout << "Letter \'" << Ch1 << " or \'" << StringCharLib::InvertLetterCase(Ch1)
    << "\' Count = " << LetterCountInStringNotMatchCase(S1, Ch1, false);
}