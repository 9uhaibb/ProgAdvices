#pragma once
#include <iostream>
#include <string>
#include "clsString.h"

#include <limits>

using namespace std;

class clsInputValiDate

{
public:
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number <= To && Number >= From);
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number <= To && Number >= From);
    }

    /*static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date >= From && Date <= To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // if the opposite, if the user replaced the parameters
        // Date >= To && Date <= From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) && (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    } */

    static int ReadIntNumber(string Errormessage)
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            // include limits
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormessage;
        }
        return Number;
    }

    static double ReadDblNumber(string Errormessage)
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            // include limits
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormessage;
        }
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string Errormessage)
    {
        int Number = ReadIntNumber(Errormessage);
        while (!IsNumberBetween(Number, From, To))
        {
            cout << Errormessage;
            Number = ReadIntNumber(Errormessage);
        }
        return Number;
    }

    static short ReadShortNumberBetween(short From, short To, string Errormessage)
    {
        short Number = ReadIntNumber(Errormessage);
        while (!IsNumberBetween(Number, From, To))
        {
            cout << Errormessage;
            Number = ReadIntNumber(Errormessage);
        }
        return Number;
    }


    static double ReadDblNumberBetween(double From, double To, string Errormessage)
    {
        double Number = ReadIntNumber(Errormessage);
        while (!IsNumberBetween(Number, From, To))
        {
            cout << Errormessage;
            Number = ReadIntNumber(Errormessage);
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
