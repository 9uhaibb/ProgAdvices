#include<iostream>
#include"clsString.h"

using namespace std;

int main ()
{
    clsString String1;
    clsString String2("  Suhaib erinat  ");

    cout << "\nUpper First letter of each word: " << String2.UpperFirstLetterOfEachWord();
    cout << "\nUpper all string: " << String2.UpperAll();
    cout << "\nLower all string:" << String2.LowerAll();

    cout << "\n\nTrim Left: " << String2.TrimLeft();
    cout << "\nTrim Right: " << String2.TrimRight();
    cout << "\nTrim : " << String2.Trim();

    cout << "\n\nwithout object:" << clsString::Trim("  Suhaib");
    //String1.


}