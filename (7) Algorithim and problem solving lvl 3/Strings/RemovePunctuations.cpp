/*
string cc type functions (returns true or false): 
toupper ()
tolower ()

isupper ()
islower ()

isdigit ()

ispunct ()
*/
#include<iostream>
#include<string>

using namespace std;

string RemoveAllPunctuations (string S1)
{
    string S2 = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

int main ()
{
    string S1 = "Welcome to Jordan, it's a; nice: country.";

    cout << "\nOriginal string :\n" << S1 << endl;

    cout << "\n\nstring after removing all punctuations:\n"
    << RemoveAllPunctuations(S1) << endl;

}