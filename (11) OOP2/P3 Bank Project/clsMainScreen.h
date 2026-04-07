#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

#include"clsCLientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteCLientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginScreen.h"
#include"clsLoginRegisterScreen.h"

#include"clsCurrencyExchange.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enManiMenueOptions {eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, LoginRegister = 8 , eCurrencyExchange = 9 ,eExit = 10
};

    static short _ReadMainMenueOption ()
    {
        cout << setw(37) << left << "" <<  "Choose what you want to do [1 - 10]? ";
        short choice = clsInputValiDate::ReadShortNumberBetween(1, 10, "Invalid Number, Enter again: ");
        return choice;
    }
    
    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }
    
    static void _ShowAllClientsScreen()
    {
        clsCLientListScreen::ShowClientsList();
    }
    
    static void _ShowAddNewClientsScreen ()
    {
        clsAddNewClientScreen::AddNewClient();
    }
    
    static void _ShowDeleteClientScreen ()
    {
        clsDeleteClientScreen::DeleteClient();
    }
    
    static void _ShowUpdateClientScreen ()
    {
        //cout << "Update Client Screen will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }
    
    static void _ShowFindClientScreen ()
    {
        //cout << "Find Client Screen will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();

    }
    
    static void _ShowTransactionsMenue ()
    {
        //cout << "Transaction Client Menue will be here...\n";
        clsTransactionScreen::ShowTransactionMenueScreen();
    }
    
    static void _ShowManageUsersMenue ()
    {
        //cout << "Menege Client Menue will be here...\n";
        clsManageUsersScreen::ShowManegeUsersMenue();
    }
    
    // static void _ShowEndScreen ()
    // {
    //     cout << "End Screen will be here...\n";
    // }

    static void _ShowLoginRegisterScreen ()
    {
        //  cout << "\n_ShowRegisterLoginScreen code will be here...\n";
        clsRegisterLoginScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeMenue()
    {
        clsCurrencyExchange::ShowCurrencyExchangeScreen();
    }

    static void _Logout ()
    {
        CurrenUser = clsUser ::Find("","");
    }
    
    static void _PerformMainMenueOption (enManiMenueOptions MainMenueOption)
    {
        system ("cls");
        switch (MainMenueOption)
        {
        case enManiMenueOptions::eListClients:
            system ("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case enManiMenueOptions::eAddNewClient:
            system ("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case enManiMenueOptions::eDeleteClient:
            system ("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case enManiMenueOptions::eUpdateClient:
            system ("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enManiMenueOptions::eFindClient:
            system ("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enManiMenueOptions::eManageUsers:
            system ("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
  
        case enManiMenueOptions::eShowTransactionsMenue:
            system ("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case enManiMenueOptions::LoginRegister:
            system ("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case enManiMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMenue();
            _GoBackToMainMenue();
            break;

        case enManiMenueOptions::eExit:
            system ("cls");
            _Logout();
            //clsLoginScreen::ShowLoginScreen();
            // wrong, the login Screen called the main screen,
            // so its wron to call the login screen from the main screen

            break;
  
        }
    }
public:
    static void ShowMainMenue ()
    {
        system("cls");
        _DrawScreenHeader("\tMain Screen");

        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left <<""<< "\t\t\tMain Menue\n";
        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Loguot.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformMainMenueOption((enManiMenueOptions)_ReadMainMenueOption());

        ;
    }
};
