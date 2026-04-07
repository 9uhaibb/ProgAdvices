#ifndef MYLIBRARY_S_
#define MYLIBRARY_S_

#include <iostream>
#include <string>

using namespace std;

namespace StringCharLib
{
    char ReadCharacter()
    {
        char c;
        cout << "Enter a Character?\n";
        cin >> c;
        return c;
    }
    string ReadString()
    {
        string S1;
        cout << "Enter string: \n";
        getline(cin, S1);

        return S1;
    }

    char InvertLetterCase(char Char1)
    {
        return (isupper(Char1) ? tolower(Char1) : toupper(Char1));
    }
    string InvertAllStringLetters(string String1)
    {
        for (int i = 0; i < String1.length(); i++)
        {
            String1[i] = StringCharLib::InvertLetterCase(String1[i]);
        }
        return String1;
    }

    enum enLetterCount {SmallLetter = 0, CapitalLetter = 1};
    int CountLetters(string String, enLetterCount LetterCount)
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

}
#endif
