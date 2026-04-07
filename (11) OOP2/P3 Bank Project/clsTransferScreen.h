#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClientCard (clsBankClient Client)
    {
        cout << "\n____________________________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance(); 
        cout << "\n____________________________________\n";
    }
    static string _ReadAccountNumber ()
    {
        string Acc;
        cout << "\nPlease Enter Account Number: ";
        Acc = clsInputValiDate::ReadString();
        
        while (!clsBankClient::IsClientExist(Acc))
        {
            cout << "Account " << Acc << " is not exist, Enter another: ";
            Acc = clsInputValiDate::ReadString();
        }

        return Acc;
    }

    static double _ReadAmount(clsBankClient Sender)
    {
        double Amount;

        cout << "\nEnter Transfer Amount? ";

        cin >> Amount;

        while (Amount > Sender.GetAccountBalance())
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            cin >> Amount;
        }
        return Amount;
    }


public:
    static void ShowTransferScreen ()
    {
        _DrawScreenHeader("Transfer Screen");

        string SenderAccNum = "", RecieverAccNum = "";

        cout << "\nTransfer from: ";
        SenderAccNum = _ReadAccountNumber();
        clsBankClient Sender = clsBankClient::Find(SenderAccNum);

        _PrintClientCard(Sender);
        
        cout << "\nTransfer To: ";
        RecieverAccNum = _ReadAccountNumber();
        clsBankClient Reciever = clsBankClient::Find(RecieverAccNum);

        _PrintClientCard(Reciever);

        double Amount = _ReadAmount(Sender);

        char Answer = 'n';
        cout << "\nare you sure you want to perform this operation (y/n)? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Sender.Transfer(Amount, Reciever, CurrenUser.GetUsername()))
            {
                cout << "\nTransfer done Successfully.\n";
            }
            else
            {
                cout << "\nTransfere Failed.\n";
            }
        }
        _PrintClientCard(Sender);
        _PrintClientCard(Reciever);





    }
};