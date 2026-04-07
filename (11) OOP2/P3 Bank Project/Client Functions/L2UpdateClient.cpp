#include<iostream>
#include"clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo (clsBankClient & Client) // & apply the changes on the original 
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

void UpdateClient ()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValiDate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nClient is not exist, Please enter another one: ";
        AccountNumber = clsInputValiDate::ReadString();
    }

    // now i have the account, i want to store ,  print , and update it

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nUpdate Client Info:";
    cout << "\n__________________\n";

    ReadClientInfo(Client);

    // now i have the new info, i need to save it on the file
    // and i want to know if the info saved succefully or on,
    // 2 option so the method is enum type:save and return:  fail, succes

    Client.Save();

}

int main ()
{
    UpdateClient();
}