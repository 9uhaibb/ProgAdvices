#pragma once
#include <iostream>
#include <string>

#include <limits>

using namespace std;

class clsInputValiDate

{
public:
    template <typename T> T static  IsNumberBetween(T Number, T From, T To)
    {
        return (Number <= To && Number >= From);
    }

    template <typename T> T static ReadNumber(string Errormessage)
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            // include limits
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormessage;
        }
        return Number;
    }

    template <typename T> T static ReadNumberBetween(T From, T To, string Errormessage)
    {
        T Number = ReadNumber <T>(Errormessage);
        while (!IsNumberBetween(Number, From, To))
        {
            cout << Errormessage;
            Number = ReadNumber <T>(Errormessage);
        }
        return Number;
    }

    /*static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
*/
    static string ReadString ()
    {
        string S;
        getline(cin >> ws, S);
        return S;
    }

};
