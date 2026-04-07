#pragma once 

#include <iostream>
#include "clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency (clsCurrency Currency)
    {
        cout << "\n______________________\n";
        cout << "\nCurrency Card:\n";
        cout << "Country   : " << Currency.Country() << endl;
        cout << "Code      : " << Currency.CurrencyCode() << endl;
        cout << "Name      : " <<  Currency.CurrencyName() << endl;
        cout << "Rate (1$) : " << Currency.Rate() << endl;
        cout << "\n______________________\n";
    }

    static void _ShowResult (clsCurrency Currency)
    {
        if (Currency.IsEmpty())
        {
            cout << "\nCurrency Found.\n";
            _PrintCurrency(Currency);
        }
        else 
        {
            cout << "\nCurrency is not found.\n";
        }
    }
public:

    static void ShowFindCurrencyScreen ()
    {
        string Title = "Find Currency Screen";
        
        _DrawScreenHeader(Title);

        short n;
        cout << "\nFind By: [1] Code or [2] Country ? \n";
        n = clsInputValiDate::ReadIntNumberBetween(1,2,"Invalid Number, Try again: ");

        if (n == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter Currency Code: ";
            CurrencyCode = clsInputValiDate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

            _ShowResult(Currency);
        }
        else 
        {
            string CountryName;
            cout << "\nPlease Enter Country Name: ";
            CountryName = clsInputValiDate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

            _ShowResult(Currency);
        }
    }
};
