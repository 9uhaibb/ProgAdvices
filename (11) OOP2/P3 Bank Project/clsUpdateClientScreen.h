#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
    static void ShowUpdateClientScreen()
    {
    if (!_IsHaveAccess(clsUser::enPermissions::UpdateClients))
    {
        return; // this will exit the function
    }
        string AccountNumber = "";

        _DrawScreenHeader("Update Client Screen");
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValiDate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient is not exist, Please enter another one: ";
            AccountNumber = clsInputValiDate::ReadString();
        }

        // now i have the account, i want to store ,  print , and update it

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nUpdate Client Info:";
        cout << "\n__________________\n";

        _ReadClientInfo(Client);

        // now i have the new info, i need to save it on the file
        // and i want to know if the info saved succefully or on,
        // 2 option so the method is enum type:save and return:  fail, succes

        Client.Save();
    }
};
