#pragma once 

#include <iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<vector>
#include<iomanip>
#include"clsDate.h"
#include"Global.h"
class clsRegisterLoginScreen : protected clsScreen
{
private:
    static void _PrintUserLoginRecordLine(clsUser::stLoginRegisterRecord User)
    {
        cout << setw(8) << left << "" << "| " << setw(34) << left << User.DateTime;
        cout << setw(8) << left << "" << "| " << setw(20) << left << User.Username;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(3) << left << User.Permissions;

    }
public:

    static void ShowLoginRegisterScreen ()
    {
        if (!_IsHaveAccess(clsUser::enPermissions::ListLoginsRegister))
        {
            return; // this will exit the function
        }

        vector <clsUser::stLoginRegisterRecord> vUsersLogins = clsUser::GetLoginRegistersList();
        string Title = "Register Login Screen";
        string SubTitle = "\t\t\t(" + to_string(vUsersLogins.size()) +") Results.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date\t-\tTime";
        cout << "| " <<  setw(20)<< left << "Username";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(3) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsersLogins.size() == 0)
            cout << "\t\t\t\tNo Users Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vUsersLogins)
            {

                _PrintUserLoginRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
    

};