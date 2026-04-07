#include<iostream>
#include<string>

using namespace std;

char ReadCharacter ()
{
    char c;
    cout << "Enter a Character?\n";
    cin >> c;
    return c;
}

char InvertCharacter (char Char1)
{
    return (isupper(Char1)? tolower(Char1) : toupper(Char1));
}

void PrintCharacter (char c)
{
    cout << "Char after inverting case:\n" << c << endl;
}

int main ()
{
    char C1 = ReadCharacter();

    C1 = InvertCharacter(C1);

    PrintCharacter(C1);
}