// print all vowels in that string

#include <iostream>
#include <string>
#include "StringCharLib.h"

using namespace std;

bool IsVowel(char Char)
{
    Char = tolower(Char);
    return ((Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u'));
}

void PrintVowels(string String)
{
    for (int i = 0; i < String.length(); i++)
    {
        if (IsVowel(String[i])) // tolower() inside IsVowel does not affect here in PrintVowels()
                                // cuz it's sent by value, so just effect on IsVowel()
        {
            cout << String[i] << "    ";
        }
    }
}

int main()
{
    string S1 = StringCharLib::ReadString();

    PrintVowels(S1);
}