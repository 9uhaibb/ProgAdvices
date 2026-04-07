#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

void DeleteClient ()
{
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
    Client.Print();

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

int main ()
{
    DeleteClient();
    system("pause>0");
    return 0;
}