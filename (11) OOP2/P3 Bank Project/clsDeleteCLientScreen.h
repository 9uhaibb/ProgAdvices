#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsString.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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
static void DeleteClient ()
{  
    if (!_IsHaveAccess(clsUser::enPermissions::DeleteClients))
    {
        return; // this will exit the function
    }
    _DrawScreenHeader("Delete Client Screen");
    string AccountNumber = "";
    cout << "Deleteing Account:\nEnter Account Number: ";
    AccountNumber = clsInputValiDate::ReadString();
//        Not
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account is not exist, Please Enter Another: ";
        AccountNumber = clsInputValiDate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    _PrintClient(Client);

    cout << "Are you sure you want to delete? (Y/N)";
    char choice = 'n';
    cin >> choice;

    if (toupper(choice) == 'Y')
    {
        // i want to make the delete method BOOL 
        // so it return true after deleting and saving the on file
        // after saving on the file i need to make the obj empty cuz it still full
        if (Client.Delete() == true)// if Deleted 
        {
            cout << "\nClient Deleted Successfully :)\n";
            Client.Print();
        }
    
        else 
        {
            cout << "\nError, CLient was not found\n";
        }
    }
}
};