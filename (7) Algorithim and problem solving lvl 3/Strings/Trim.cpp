// Trim string :
/* string :"   Suhaib omar erinat   ""

Trim Left :"Suhaib omar erinat   "
Trim Right:"   Suhaib omar erinat" 
Trim : "Suhaib omar erinat"*/


#include<iostream>
#include<string>

using namespace std;
// the idea is to return the whole string with the changes

string TrimLeft (string S1)
{
    for (int i = 0; i <= S1.length(); i++) // start from the start of the string to the last position
    {
        if (S1[i] != ' ') // if i is char
        {
            return S1.substr(i, S1.length() - i); // cut from i to total string length - i
        }
        // if not char, repeat go to the next position
    }
    return "";
}

string TrimRight (string S1)
{
    for (int i = S1.length() - 1; i >= 0; i--) // strart from the last position to the start of the string
    {//                      - 1 cuz the length() start from 1 not 0,
    //                       we need it with 0 to use it in the loop
        if (S1[i] != ' ') // if i is char
        {
            return S1.substr(0, i + 1); // cut from the start of the string to i position
            //                 + 1 cuz i position itself will be deleted
            //                  thats how substr() works, so we add 1 to include i position 
        }
    }
    return "";
}

string Trim (string S1)
{
    return TrimLeft(TrimRight(S1));
}

int main ()
{
    string S1 = "   Suhaib Omar Erinat  ";

    cout << "Orginal String :(" << S1 << ")" ;

    cout << "\nTrim Left      :(" << TrimLeft(S1) << ")";
    cout << "\nTrim Right     :(" << TrimRight(S1) << ")";
    cout << "\nTrim           :(" << Trim(S1) << ")";

    system("pause>0");
}