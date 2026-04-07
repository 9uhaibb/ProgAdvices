#pragma once

#include <iostream>
#include<fstream>
#include<vector>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsString.h"
#include<iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
    
    static void _PrintTransferRecord(clsBankClient::stTransferLogRecord Record)
    {
        cout << setw(8) << left << "" << "| " << left << setw(22) << Record.DateTime;
        cout << "| " << left << setw(11) << Record.SenderAccNum;
        cout << "| " << left << setw(11) << Record.RecieverAccNum;
        cout << "| " << left << setw(12) << Record.Amount;
        cout << "| " << left << setw(11) << Record.SenderFinalBalance;
        cout << "| " << left << setw(11) << Record.RecieverFinalBalance;;
        cout << "| " << left << setw(9) << Record.SenderUsername << "|";
    }

public:

    static void ShowTransferLogScreen ()
    {
        vector <clsBankClient::stTransferLogRecord> vTransfers = clsBankClient::GetTransferLogList();

        string Title = "Transfer Log Screen";
        string SubTitle = "\t\t(" + to_string(vTransfers.size()) + ") Record(s)";

        _DrawScreenHeader(Title,SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date - Time";
        cout << "| " << left << setw(11) << "s.Acct";
        cout << "| " << left << setw(11) << "r.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(11) << "s.balance";
        cout << "| " << left << setw(11) << "r.balance";
        cout << "| " << left << setw(9) << "User" << "|";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransfers.size() == 0)
        {
            cout << "\t\t\t\tNo Transfers Logins Available In the System!";
        }
        else 
        {
            for (clsBankClient::stTransferLogRecord Record : vTransfers)
            {
                _PrintTransferRecord(Record);
                cout <<endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};