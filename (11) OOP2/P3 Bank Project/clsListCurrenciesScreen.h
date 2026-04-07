#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>

using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout <<  "| " << left << setw(30) << Currency.Country();
        cout <<  "| " << left << setw(5) << Currency.CurrencyCode();
        cout <<  "| " << left << setw(39) << Currency.CurrencyName();
        cout <<  "| " << left << setw(12) << Currency.Rate() << "|\n";
    }

public:

    static void ShowListCurrenciesScreen ()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList(); 
        string Title = "Currencies List Screen";
        string SubTitle = "\t\t(" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << left << setw(10) << "" << "____________________________________________";
        cout << "___________________________________________________\n";
        
        cout << left << setw(10) << "" << "| " << left << setw(29) << "Country";
        cout << "| " << left << setw(5) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(12) << "Rate" << "|\n";

        cout << left << setw(10) << "" << "____________________________________________";
        cout << "___________________________________________________\n";

        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\tNo Data.";
        }

        for (clsCurrency & C : vCurrencies)
        {
            cout << left << setw(10) << "";
            _PrintCurrency(C);
        }
        cout << left << setw(10) << "" << "___________________________________________";
        cout << "___________________________________________________\n";
    }
};