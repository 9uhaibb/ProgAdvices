#include<iostream>
#include"clsBankClient.h"
#include<vector>
#include"clsUtil.h"
#include<iomanip>

void PrintClientRecordBalanceLine (clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(20) << Client.FullName();
    cout << "| " << left << setw(8) << Client.GetAccountBalance() << "|\n";
}

void ShowTotalBalances ()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    double TotalBalances = clsBankClient::GetTotalBalances();

    cout <<"\n\t\tBalances List (" << vClients.size() << ")\n";
    cout << "__________________________________________________\n";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Name";
    cout << "| " << left << setw(8) << "Balance" << "|";

    cout << "\n__________________________________________________\n";

    if (vClients.size() == 0)
    {
        cout <<"\n\t\tNo Data\n";
    }
    else
    {
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
        }
        cout << "__________________________________________________\n";
        cout << "\t\tTotal Balances: " << TotalBalances << endl;
        cout << clsUtil::NumberToText((int)TotalBalances) << endl;
    }


}

int main ()
{
    ShowTotalBalances();
}