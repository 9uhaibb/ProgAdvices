#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<iostream>

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo (clsUser User)
    {
        // cout << "Read User info will be here..\n";
        cout << "\nEnter First Name: ";
        User.SetFirstName(clsInputValiDate::ReadString());

        cout << "\nEnter Last Name: ";
        User.SetLastName(clsInputValiDate::ReadString());

        cout << "\nEnter Email: ";
        User.SetEmail(clsInputValiDate::ReadString());

        cout << "\nEnter Phone: ";
        User.SetPhone(clsInputValiDate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValiDate::ReadString());

        cout << "\nEnter Permissions: ";
        User.SetPermossions(_ReadPermissionsToSet());
    }
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

    static int _ReadPermissionsToSet ()
    {
         int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::ListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::AddClients;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::DeleteClients;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::UpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::FindClients;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::Tranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::ManageUsers;
        }

        cout << "\nShow Login Register(History)? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::ListLoginsRegister;
        }

        return Permissions;
    }

public:
    static void ShowAddNewUserScreen ()
    {
        string Title = "\tAdd New User";

        _DrawScreenHeader(Title);

        string Username;
        cout << "\nPlease Enter Username: ";
        Username = clsInputValiDate::ReadString();

        while (clsUser::IsUserExist(Username))
        {
            cout << endl << Username << " Already exist, Enter another: ";
            Username = clsInputValiDate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(Username);

        _ReadUserInfo(NewUser);
        
        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
            case clsUser::enSaveResults::svFailedEmptyObject:
                cout << "\nFailed to save, the object is empty.\n";
                break;
            case clsUser::enSaveResults::svFailedUsernameExist:
                cout << "\nFailed to save, the Username already exist.\n";
                break;
            case clsUser::enSaveResults::svSucceeded:
                cout << "\nUser Added Successfuly.\n";
                _PrintUser(NewUser);
        }

    }
};