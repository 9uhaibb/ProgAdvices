#pragma once

#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

public:
    static void ShowFindClientScreen()
    {
    if (!_IsHaveAccess(clsUser::enPermissions::FindClients))
    {
        return; // this will exit the function
    }
        string AccountNumber = "";

        _DrawScreenHeader("Find Client Screen");
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValiDate::ReadString();

        //Find() returns empty obj if there is no account number found
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        if (Client.IsEmpty())
            cout << "\nClient is not found";
        else 
            cout << "\nClient found.";

        _PrintClient(Client);
    }
};