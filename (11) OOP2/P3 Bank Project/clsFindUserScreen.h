#pragma once

#include<iostream>
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsScreen.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{

private:
    static void _PrintUser (clsUser User)
    {
        //cout << "Print User info will be here..\n";
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nPermissions : " << User.GetPermossions();
        cout << "\n___________________\n";
    }

public:
    static void ShowFindUserScreen()
    {
        string Username = "";

        _DrawScreenHeader("Find User Screen");
        cout << "\nPlease Enter Username: ";
        Username = clsInputValiDate::ReadString();

        //Find() returns empty obj if there is no Username found
        clsUser User = clsUser::Find(Username);
        if (User.IsEmpty())
            cout << "\nUser is not found";
        else 
            cout << "\nUser found.";

        _PrintUser(User);
    }
};