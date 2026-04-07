#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include <iomanip>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(30) << Client.FullName();
        cout << "| " << left << setw(8) << Client.GetAccountBalance() << "|\n";
    }

public:
    static void ShowTotalBalancesScreen ()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string SubTitle = "(" + to_string(vClients.size()) + ") Clients";
        double TotalBalances = clsBankClient::GetTotalBalances();

        _DrawScreenHeader("Total Balances Screen", SubTitle);
//                          10
        cout << left << setw(28) << "" << "____________________________________________________________\n";

        cout << left << setw(28) << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(8) << "Balance" << "|\n";

        cout << left << setw(28) << "" << "____________________________________________________________\n";

        if (vClients.size() == 0)
        {
            cout << left << setw(28) << "" << "\n\t\t\t\t\tNo Data\n";
        }
        else
        {
            // short Number = 1;
            for (clsBankClient Client : vClients)
            {

                // cout << left << setw(3) << Number;
                cout << left << setw(28) << "";
                _PrintClientRecordLine(Client);
                // Number++;
            }
        }
        cout << left << setw(28) << "" << "____________________________________________________________\n";

        _DrawScreenHeader(to_string(TotalBalances), clsUtil::NumberToText(int(TotalBalances)));

        


    }

};

