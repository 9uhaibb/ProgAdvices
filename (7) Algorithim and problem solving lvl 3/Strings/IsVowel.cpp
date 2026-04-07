// Read character then check if it is a vowel or not
// (Vowels are : a, e, i, o, u)

#include<iostream>
#include<string>
#include"StringCharLib.h"

using namespace std;

bool IsVowel (char Char)
{
    Char = tolower(Char);
    return ((Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u'));
}

int main ()
{
    char Ch1 = StringCharLib::ReadCharacter();

    if (IsVowel(Ch1) == true)
    {
        cout << "Yes, Letter \'" << Ch1 << "\' is Vowel\n";
    }
    else 
    {
        cout << "No, Letter \'" << Ch1 << "\' is not Vowel\n";
    }
}