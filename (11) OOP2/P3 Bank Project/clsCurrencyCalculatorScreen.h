#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
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

    static clsCurrency _LoopCheckCurrencyExistByCode (string CurrencyCode)
    {
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        while (!Currency.IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency with code (" << CurrencyCode
            << ") is not exist, Please enter another:\n";

        CurrencyCode = clsInputValiDate::ReadString();
        clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
        }

        return Currency;
    }
    
public:
    static void ShowCurrencyCalculatorScreen()
    {
        char choice = 'n';

        do
        {
            system("cls");
            _DrawScreenHeader("Currency Calculator");
            
            cout << "\nEnter Currency1 Code:\n";
            string Currency1Code;
            Currency1Code = clsInputValiDate::ReadString();
            clsCurrency CurrencyFrom = _LoopCheckCurrencyExistByCode(Currency1Code);

            cout << "\nEnter Currency2 Code:\n";
            string Currency2Code;
            Currency2Code = clsInputValiDate::ReadString();
            clsCurrency CurrencyTo = _LoopCheckCurrencyExistByCode(Currency2Code);

            double Amount = 0;

            cout << "\nEnter Amount to Exchange(" << CurrencyFrom.CurrencyCode() << "): ";
            cin >> Amount;

            cout << "\nConvert From:\n";
            _PrintCurrency(CurrencyFrom);

            float Result = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

            cout << Amount << " " <<  Currency1Code << " = " 
            << Result << " " << Currency2Code << endl;

            cout << "\nDo You want to perform anothe Calculation? (Y/N) ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
};