// count vowels

#include<iostream>
#include"StringCharLib.h"
#include<string>

using namespace std;

    string ReadString()
    {
        string S1;
        cout << "Enter string: \n";
        getline(cin, S1);

        return S1;
    }

bool IsVowel (char Char)
{
    Char = tolower(Char);
    return ((Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u'));
}

int CountVowels (string String)
{
    int VowelsCounter = 0;
    for (int i = 0; i < String.length(); i++)
    {
        if (IsVowel(String[i]))
        {
            VowelsCounter++;
        }
    }
    return VowelsCounter;
}

int main ()
{
    string S1 = StringCharLib::ReadString();

    cout << "Number of vowels is : " << CountVowels(S1) << endl;
}