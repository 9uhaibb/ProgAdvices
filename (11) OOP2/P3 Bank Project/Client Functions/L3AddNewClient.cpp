#include<iostream>
#include"clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void AddNewClient () 
{
    cout << "Adding new Client, Enter Account Number: ";
    string AccountNumber = clsInputValiDate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account already exist, Please try again: ";
        AccountNumber = clsInputValiDate::ReadString();
    }

    // to store the _Mode , AccountNumber
    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    clsBankClient::ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nClient saved Successfully.";
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved because it's Empty";
        break;

    
        case clsBankClient::enSaveResults::svFailedAccountNumberExist:
    
            cout << "\nError account was not saved because account number is used!\n";
            break;

    }

}

int main ()
{
    AddNewClient();
    system("pause>0");
    return 0;
}