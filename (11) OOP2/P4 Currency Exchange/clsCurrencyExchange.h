#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"

#include<iomanip>
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyExchange : protected clsScreen
{
private:

    enum enCurrencyExchange {ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, 
                            CurrencyCalculator = 4, MainMenue = 5};

    static short _ReadMainMenueOption ()
    {
        cout << setw(37) << left << "" <<  "Choose what you want to do [1 - 10]? ";
        short choice = clsInputValiDate::ReadShortNumberBetween(1, 10, "Invalid Number, Enter again: ");
        return choice;
    }
    
    static void _GoBackToCurrencyMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrenciesScreen ()
    {
        cout << "\nList Currencies will be here...\n";
    }

    static void _ShowFindCurrencyScreen ()
    {
        cout << "\tFind Currencies will be here...\n";
    }

    static void _ShowUpdateRateScreen()
    {
        cout << "\nUpdate Rate will be here...\n";
    }
    
    static void _ShowCurrencyCalculatorScreen ()
    {
        cout << "\nCurrency Calculator will be here...\n";
    }

    static void _PerformCurrencyExchangeMenueOptions (enCurrencyExchange Option)
    {
        system ("cls");
        switch (Option)
        {
            case enCurrencyExchange::ListCurrencies:
                system("cls");
                _ShowListCurrenciesScreen();
                _GoBackToCurrencyMenue();
                break;
            case enCurrencyExchange::FindCurrency:
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyMenue();
                break;
            case enCurrencyExchange::UpdateRate:
                system("cls");
                _ShowUpdateRateScreen();
                _GoBackToCurrencyMenue();
                break;
            case enCurrencyExchange::CurrencyCalculator:
                system("cls");
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrencyMenue();
                break;
            case enCurrencyExchange::MainMenue:
                system("cls");
                break;
        }
    }
public:
    static void ShowCurrencyExchangeScreen ()
    {
        system("cls");
        string Title = "Currency Exchange Screen";

        _DrawScreenHeader(Title);

        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left <<""<< "\tCurrency Exchange Main Menue\n";
        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currancy.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currancy Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";

        _PerformCurrencyExchangeMenueOptions((enCurrencyExchange)_ReadMainMenueOption());


    }
};