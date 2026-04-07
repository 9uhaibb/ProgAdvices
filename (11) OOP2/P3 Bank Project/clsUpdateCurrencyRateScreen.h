#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;
// Read Currency Code
// Print the Card
// Confirm y-n

// Read New rate
// Update
// Print the card
class clsUpdateCurrencyRateScreen : protected clsScreen
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

public:

    static void ShowUpdateCurrencyRateScreen ()
    {
        _DrawScreenHeader("Update Rate Screen");

        cout << "\nEnter Currency Code: ";
        string CurrencyCode = clsInputValiDate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        while (Currency.IsEmpty())
        {
            cout << "\nCurrency is not found\n";
            CurrencyCode = clsInputValiDate::ReadString();
            Currency = clsCurrency::FindByCode(CurrencyCode);
        }

        _PrintCurrency(Currency);

        char choice = 'n';
        cout << "\nAre you sure to update the rate of  this currency? (y/n) ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            double NewRate = 0;

            cout << "\nEnter New Rate: ";
            cin >> NewRate;

            Currency.UpdateRate(NewRate);

            cout << "\nCurrency Rate Updated Successfully.\n";

            _PrintCurrency(Currency);
        }
        else 
        {
            return;
        }
    }
};