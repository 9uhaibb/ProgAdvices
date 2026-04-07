#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsString.h"
#include"clsUser.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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
    static void _ReadClientInfo(clsBankClient &Client) // & apply the changes on the original
    {
        cout << "\nEnter First Name: ";
        Client.SetFirstName(clsInputValiDate::ReadString());

        cout << "\nEnter Last Name: ";
        Client.SetLastName(clsInputValiDate::ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValiDate::ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValiDate::ReadString());

        cout << "\nEnter Pin Code: ";
        Client.SetPinCode(clsInputValiDate::ReadString());

        cout << "\nEnter Balance: ";
        Client.SetAccountBalance(clsInputValiDate::ReadDblNumber("Invalid nubmer type, Try again"));
    }
public:
    static void AddNewClient()
    {
        if (!_IsHaveAccess(clsUser::enPermissions::AddClients))
        {
            return; // this will exit the function
        }
        clsScreen::_DrawScreenHeader("Add Client Screen");

        cout << "Adding new Client, Enter Account Number: ";
        string AccountNumber = clsInputValiDate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account already exist, Please try again: ";
            AccountNumber = clsInputValiDate::ReadString();
        }

        // to store the _Mode , AccountNumber
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nClient saved Successfully.";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            break;

        case clsBankClient::enSaveResults::svFailedAccountNumberExist:

            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
    }
};