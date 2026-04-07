#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
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
    static void ShowUpdateUserScreen()
    {
        string Username = "";

        _DrawScreenHeader("Update User Screen");
        cout << "\nUsername Number: ";
        Username = clsInputValiDate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUser is not exist, Please enter another one: ";
            Username = clsInputValiDate::ReadString();
        }

        // now i have the account, i want to store ,  print , and update it

        clsUser User = clsUser::Find(Username);
        _PrintUser(User);

        cout << "\nUpdate User Info:";
        cout << "\n__________________\n";

        _ReadUserInfo(User);

        // now i have the new info, i need to save it on the file
        // and i want to know if the info saved succefully or on,
        // 2 option so the method is enum type:save and return:  fail, succes

        User.Save();
    }
};
