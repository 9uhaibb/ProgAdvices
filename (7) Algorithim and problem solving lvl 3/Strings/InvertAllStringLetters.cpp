#include<iostream>
#include<string>

using namespace std;

string ReadString ()
{
    string S1;
    cout << "Enter String?\n";
    getline(cin, S1 );
    return S1;
}

string InvertAllStringLetters (string S1)
{
    for (int i = 0; i <= S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            S1[i] = toupper(S1[i]);
        }
        else 
        {
            S1[i] = tolower(S1[i]);
        }
    }
    return S1;
}

int main ()
{
    string S1 = ReadString ();
    cout << InvertAllStringLetters (S1);
}