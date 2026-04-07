#pragma once

#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include <iomanip>

#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"


using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
    enum enManageUsersOptions {ListUsers = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5,
        BackToManageUsers = 6};

    static short _ReadManageUsersOption ()
    {
        cout << setw(37) << left << "" <<  "Choose what you want to do [1 - 6]? ";
        short choice = clsInputValiDate::ReadShortNumberBetween(1, 6, "Invalid Number, Enter again: ");
        return choice;
    }
    
    static void _GoBackToManageUsers()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

        system("pause>0");
        ShowManegeUsersMenue();
    }

    static void _ShowAllUsersScreen()
    {
        //cout << "\nList Users Will Be Here...\n";
        clsListUsersScreen::ShowUsersList();
    }
    static void _ShowAddNewUserScreen ()
    {
        // cout << "\nAdd New Users Will Be Here...\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
        
    }
    static void _ShowDeleteUserScreen ()
    {
        // cout << "\nDelete Users Will Be Here...\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }
    static void _ShowUpdateUserScreen ()
    {
        // cout << "\nUpdate Users Will Be Here...\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen ()
    {
        // cout << "\nFind Users Will Be Here...\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

        static void _PerformManageUsersOption (enManageUsersOptions Option)
    {
        system ("cls");
        switch (Option)
        {
        case enManageUsersOptions::ListUsers:
            system ("cls");
            _ShowAllUsersScreen();
            _GoBackToManageUsers();
            break;
        case enManageUsersOptions::AddUser:
            system ("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsers();
            break;
        case enManageUsersOptions::DeleteUser:
            system ("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsers();
            break;
        case enManageUsersOptions::UpdateUser:
            system ("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsers();
            break;

        case enManageUsersOptions::FindUser:
            system ("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsers();
            break;

        case enManageUsersOptions::BackToManageUsers:
            system ("cls");
            break;
        }
    }

    

public:
    static void ShowManegeUsersMenue ()
    {
    if (!_IsHaveAccess(clsUser::enPermissions::ManageUsers))
    {
        return; // this will exit the function
    }
        system("cls");
        _DrawScreenHeader("Manage Users Screen");

        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left <<""<< "\t\t\tMenue\n";
        cout << setw(37) << left <<""<< "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show User List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Back To Main Menue.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());

        ;
    }

};