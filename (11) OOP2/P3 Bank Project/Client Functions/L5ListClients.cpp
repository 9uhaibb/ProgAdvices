#include <iostream>
#include "clsBankClient.h"
#include<vector>
#include <iomanip>

using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(20) << Client.FullName();
    cout << "| " << left << setw(12) << Client.GetPhone();
    cout << "| " << left << setw(20) << Client.GetEmail();
    cout << "| " << left << setw(8) << Client.GetPinCode();
    cout << "| " << left << setw(8) << Client.GetAccountBalance() << "|\n";
}
void ShowClientsList ()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\t\t\t\t\tClients (" << vClients.size() << ")\n\n"; 

    cout << "____________________________________________";
    cout << "___________________________________________________\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(8) << "Pin Code";
    cout << "| " << left << setw(8) << "Balance" << "|";

    cout << "\n___________________________________________";
    cout << "___________________________________________________\n";
    if (vClients.size() == 0)
    {
        cout << "\n\t\t\t\t\tNo Data\n";
    }
    else 
    {
        //short Number = 1;
        for (clsBankClient Client : vClients)
        {
            
            //cout << left << setw(3) << Number;
            PrintClientRecordLine(Client);
            //Number++;
        }
    }
    cout << "____________________________________________";
    cout << "___________________________________________________\n";
}


int main ()
{
    ShowClientsList();
}