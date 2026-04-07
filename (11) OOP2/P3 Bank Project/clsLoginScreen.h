#pragma once 

#include <iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"Global.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:
    static bool _Login ()
    {
        bool LoginFailed = false;
        string Username, Password;
        short Trails = 3;

        do 
        {
            if (LoginFailed)
            {
                Trails--;

                cout << "\nInvalid Username/Password, Try again.\n";
                cout << "You have " << Trails << " Trails to login.\n";
            }

            if (Trails == 0)
            {
                cout << "\nYou are locked after 3 failed trails.\n\n";
                return false;
            }
            cout << "\nEnter Username: ";
            Username = clsInputValiDate::ReadString();

            cout << "\nEnter Password: ";
            Password = clsInputValiDate::ReadString();

            CurrenUser = clsUser::Find(Username,Password);

            LoginFailed = CurrenUser.IsEmpty();

        } while (LoginFailed);
        
        CurrenUser.LoginRegisters();
        clsMainScreen::ShowMainMenue();
        
        return true;
    }
public:
    static bool ShowLoginScreen ()
    {
        system("cls");
        _DrawScreenHeader("\tLogin Screen");
        return _Login();
    }
};