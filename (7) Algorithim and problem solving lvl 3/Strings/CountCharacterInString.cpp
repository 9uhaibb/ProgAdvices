// Read string and a character, then
// count the character in that string

/*F: 1- Read string, 2- Read Character
     3- count letter*/

#include<iostream>
#include<string>
#include"StringCharLib.h"

using namespace std;

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

    cout << "Letter '" << Ch1 << "' Count = " << LetterCountInStringMatchCase(S1, Ch1) << endl;
}