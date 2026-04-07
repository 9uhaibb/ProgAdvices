#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include"clsUser.h"

using namespace std;

class clsCLientListScreen : protected clsScreen

{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.GetPhone();
        cout << "| " << left << setw(20) << Client.GetEmail();
        cout << "| " << left << setw(8) << Client.GetPinCode();
        cout << "| " << left << setw(8) << Client.GetAccountBalance() << "|\n";
    }
public:
    static void ShowClientsList()
    {
        if (!_IsHaveAccess(clsUser::enPermissions::ListClients))
        {
            return; // this will exit the function
        }

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "Client List Screen";
        string SubTitle = "                 (" + to_string(vClients.size()) + ") Clients";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << left << setw(10) << "" << "____________________________________________";
        cout << "___________________________________________________\n";
        cout << left << setw(10) << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(8) << "Pin Code";
        cout << "| " << left << setw(8) << "Balance" << "|\n";

        cout << left << setw(10) << "" << "___________________________________________";
        cout << "___________________________________________________\n";
        if (vClients.size() == 0)
        {
            cout << left << setw(10) << "" << "\n\t\t\t\t\tNo Data\n";
        }
        else
        {
            // short Number = 1;
            for (clsBankClient Client : vClients)
            {

                // cout << left << setw(3) << Number;
                cout << left << setw(10) << "";
                _PrintClientRecordLine(Client);
                // Number++;
            }
        }
        cout << left << setw(10) << ""<< "____________________________________________";
        cout << "___________________________________________________\n";
    }
};