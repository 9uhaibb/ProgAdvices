#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"



using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:
    enum enTransactionMenueOptions {Deposite = 1, Withdraw = 2, ShowTotalBalances = 3,
    Transfer = 4, TransferLog = 5,  MainMenue = 6 };

    static short _ReadMainMenueOption ()
    {
        cout << setw(37) << left << "" <<  "Choose what you want to do [1 - 6]? ";
        short choice = clsInputValiDate::ReadShortNumberBetween(1, 6, "Invalid Number, Enter again: ");
        return choice;
    }
    
    static void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
        ShowTransactionMenueScreen();
    }
    
    static void _ShowDepositeScreen()
    {
        //cout << "\nShow Deposite Screen will be here..\n";
        clsDepositScreen::ShowDepositeScreen();
    }
    
    static void _ShowWithdrawScreen ()
    {
        //cout << "\nShow Withdraw Screen will be here..\n";
        clsWirhdrawScreen::ShowWirhdraweScreen();
    }
    
    static void _ShowTotalBalancesScreen ()
    {
        //cout << "\nShow Total Balances Screen will be here..\n";
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        // cout << "\nTransfere Screen will be here...\n";
        clsTransferScreen::ShowTransferScreen();
    }
    
    static void _ShowTransferLogScreen ()
    {
        // cout << "\nShowTransferLogScreen will be here..\n";
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerformTransactionMenueOptions (enTransactionMenueOptions MainMenueOption)
    {
        system ("cls");
        switch (MainMenueOption)
        {
        case enTransactionMenueOptions::Deposite:
            system ("cls");
            _ShowDepositeScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionMenueOptions::Withdraw:
            system ("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionMenueOptions::ShowTotalBalances:
            system ("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionMenueOptions::Transfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionMenueOptions::TransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
        case enTransactionMenueOptions::MainMenue:
            system ("cls");
            //_GoBackToTransactionsMenue();
            break;

        }
    }
public:
    static void ShowTransactionMenueScreen ()
    {
    if (!_IsHaveAccess(clsUser::enPermissions::Tranactions))
    {
        return; // this will exit the function
    }
        system("cls");
        _DrawScreenHeader("Transactions");

        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left <<""<< "\t\t  Transactions Menue\n";
        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Show Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Back to Main Menue.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformTransactionMenueOptions((enTransactionMenueOptions)_ReadMainMenueOption());

        ;
    }
};
