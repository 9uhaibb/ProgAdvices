#pragma once 

#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"


using namespace std;

class clsWirhdrawScreen : protected clsScreen
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
    static void ShowWirhdraweScreen ()
    {
        _DrawScreenHeader("Withdraw Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValiDate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with Account Number " << AccountNumber
             << " is not exist, Enter anothe: ";
             AccountNumber = clsInputValiDate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "Enter amount: ";
        Amount = clsInputValiDate::ReadDblNumberBetween(1, Client1.GetAccountBalance(),
         "This is Higher than the account balance, Try again please: ");

        char choice = 'n';
        cout << "Are you sure you want to perform this transaction? (y/n) ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            Client1.Withdraw(Amount);
            cout << "\nAmount Withdrawed Successfully.\n";
            cout << "\nNew Balance is:" << Client1.GetAccountBalance();
        }
        else
        {
            cout << "\nOperation cancelled\n";
        }
      
    }
};
