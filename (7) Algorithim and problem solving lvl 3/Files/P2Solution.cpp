#include <iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

enum enMainMenuOptions 
{
    eShowClientList = 1, eAddClient =2,
    eDeleteClient = 3, eUpdateClientInfo = 4,
    eFindCLient = 5, eTransactions = 6 ,eExit = 7
};
enum enTransactionsOptions 
{
    eDeposit = 1, eWithdraw = 2,
    eTotalBalances = 3, eBack = 4
};

struct stClient
{
    string AccountNumber ;
    string PinCode ;
    string Name ;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
};

const string ClientsFileName = "Clients.txt";
void GoBackToMainMenu();
void GoBackToTranactionMenu();
void ShowMainMenu ();
void ShowTransactionScreen ();

vector <string>  SplitString (string String, string Delim)
{
    vector <string> vString;

    short Position = 0;
    string sWord;

    while((Position = String.find(Delim)) != std::string::npos)
    {
        sWord = String.substr(0, Position);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        String.erase(0, Position + Delim.length());
    }

    // now there still the last word and the loop can't reach it.
    if (String != "")
    {
        vString.push_back(String); // added it to the vector
    }
    return vString;
}
stClient ConvertLineDataToRecord (string LineData, string Seperator = "#//#")
{
    stClient Client;
    vector <string> vClientData;

    vClientData = SplitString(LineData, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //casting from string to double

    return Client;
}
string ConvertRecordToLine (stClient Client, string Seperator = "#//#")
{
    string DataLine;
    DataLine += Client.AccountNumber + Seperator;
    DataLine += Client.PinCode + Seperator;
    DataLine += Client.Name + Seperator;
    DataLine += Client.PhoneNumber + Seperator;
    DataLine += to_string(Client.AccountBalance);
    return DataLine;
}
vector <stClient> LoadClientsDataFromFile (string FileName)
{
    vector <stClient> VectorOfClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stClient StructClient;

        while (getline(MyFile, Line))
        {
            StructClient = ConvertLineDataToRecord(Line);

            VectorOfClients.push_back(StructClient);
        }

        MyFile.close();
    }

    return VectorOfClients;

}
void PrintSingleClient (stClient StructClient)
{
    cout << "| " << left << setw(15) << StructClient.AccountNumber ;
    cout << "| " << left << setw(10) << StructClient.PinCode;
    cout << "| " << left << setw(25) << StructClient.Name;
    cout << "| " << left << setw(12) << StructClient.PhoneNumber;
    cout << "| " << left << setw(15) << StructClient.AccountBalance << " |";

}
void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << endl;
}
void PrintAllvClientsElements(vector <stClient> VectorOfClients)

{
    cout << "\n\t\t\t\t Clients list (" << VectorOfClients.size() << ")\t\t\t\t\n";
    cout << "__________________________________________________"
         << "______________________________________" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(25) << "Name";
    cout << "| " << left << setw(12) << "Phone Number";
    cout << "| " << left << setw(10) << "Account Balance |";

    cout << endl;
    cout << "__________________________________________________"
         << "______________________________________" << endl;

    for (stClient StructClient : VectorOfClients)
    {
        PrintSingleClient(StructClient);
        cout << endl;
    }
    cout << "__________________________________________________"
         << "______________________________________" << endl;

}
bool FindClientByNumberInFile(string AccountNumber)
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (stClient C : vClients)
    {
        if (AccountNumber == C.AccountNumber)
        {
            return true;
        }
    }
    cout << "Account [" << AccountNumber << "] is not exist!"; 
    return false;
}

stClient ReadClient ()
{
    stClient Client ;

    // usage of std::ws will extract all the whitespace character
    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);
    while (FindClientByNumberInFile(Client.AccountNumber))
    {
        cout << "\nClinet with [" << Client.AccountNumber << "] already exist!\nEnter anothe account number: ";
        getline(cin >> ws, Client.AccountNumber);
    }
    cout << "Enter Pin Code: ";
    getline(cin, Client.PinCode);
    
    cout << "Enter Name: ";
    getline(cin, Client.Name);
    
    cout << "Enter Phone Number: ";
    getline(cin, Client.PhoneNumber);
    
    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}
// 1. show Client List
void PrintClientsList (string FileName)
{
    vector <stClient> VectorOfClients = LoadClientsDataFromFile (ClientsFileName);

    PrintAllvClientsElements (VectorOfClients);
}

//2. add client
void AddLineToFile (string FileName, string Line)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << Line << endl;
        MyFile.close();
    }
}
void AddNewClient ()
{
    stClient Client;
    Client = ReadClient();
    AddLineToFile (ClientsFileName, ConvertRecordToLine(Client));
}
void AddNewCliantToFileScreen ()
{
    cout << "------------------------------" << endl;
    cout << "     Adding Client Screen     " << endl;
    cout << "------------------------------" << endl;
    char AddMore = 'Y';
    do
    {
        system ("cls");
        cout << "Adding new Client:\n\n";

        AddNewClient ();
        cout << "\nClient Added Successfully, do you want to add more?\n";
        cin >> AddMore;
    } while (AddMore == 'y' || AddMore == 'Y');
}

//3. delete client
string ReadClientNumber ()
{
    string AccountNumber;
    cout << "Enter Accont Number:";
    cin >> AccountNumber;
    return AccountNumber;
}
bool FindClientByAccountNumber (string AccountNumber, vector <stClient> vClients, stClient &Client)
{
    for (stClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber (string AccountNumber, vector<stClient> &vClients)
{
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete =true;
            return true;
        }
    }
    return false;
}
vector <stClient> SavevClientsDataToFile (string FileName, vector<stClient> vCLients)
{
    fstream MyFile;
    string DataLine;
    MyFile.open(FileName, ios::out); // overwrite
    if (MyFile.is_open())
    {

        for (stClient &C : vCLients) // C by reff
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vCLients; // we edit the file context using it
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        PrintClientCard(Client);
        cout << "\nAre You Sure you want to delete this Client? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SavevClientsDataToFile(ClientsFileName,vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "Clinet Deleted Successfully.\n";
            return true;
        }
        else
        {
            system("cls");
            cout << "\nReturning to the main menu...\n";
            GoBackToMainMenu();  // العودة للقائمة الرئيسية
            return false;
        }
    }
    else 
    {
    system("cls");
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            cout << "\nReturning to the main menu...\n";
            GoBackToMainMenu();  // العودة للقائمة الرئيسية
     return false;
    }
}
void ShowDeleteClientControlScreen ()
{
    cout << "------------------------------" << endl;
    cout << "     Delete Client Screen     " << endl;
    cout << "------------------------------" << endl;
    string AccountNumber = ReadClientNumber();
    vector <stClient> vCLients = LoadClientsDataFromFile(ClientsFileName);

    DeleteClientByAccountNumber(AccountNumber,vCLients);
}

// 4. Update Client
bool MarkClientForUpdateByAccountNumber (string AccountNumber, vector<stClient> &vClients)
{
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForUpdate =true;
            return true;
        }
    }
    return false;
}
stClient ChangeClientRecord (string AccountNumber)
{
    stClient Client ;

    Client.AccountNumber = AccountNumber;  

    cout << "\n\nEnter Pin Code: ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name: ";
    getline(cin, Client.Name);
    
    cout << "Enter Phone Number: ";
    getline(cin, Client.PhoneNumber);
    
    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}
void SaveChangesToFile (string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out/*write mode*/);

    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}
bool UpdateClientByAccountNumber (string AccountNumber, vector <stClient> & vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        PrintClientCard(Client);
        cout << "\nAre You Sure you want to update this client? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            for (stClient &C : vClients) // C by reff
            {
                if (C.AccountNumber == AccountNumber)
                {
                    cout << "Updating client: " << AccountNumber << endl;
                    C = ChangeClientRecord(AccountNumber);
                    break; // quiet the loop (important)
                }
            }
            SaveChangesToFile(ClientsFileName,vClients);
            return true;
        }
        else
        {
            system("cls");
            cout << "\nReturning to the main menu...\n";
            GoBackToMainMenu();  // العودة للقائمة الرئيسية
            return false;
        }
    }
    else 
    {
    system("cls");
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            cout << "\nReturning to the main menu...\n";
            GoBackToMainMenu();  // العودة للقائمة الرئيسية
     return false;
    }
}
void ShowUpdateClientControlScreen ()
{
    cout << "------------------------------" << endl;
    cout << "     Update Client Screen     " << endl;
    cout << "------------------------------" << endl;
    string AccountNumber = ReadClientNumber();
    vector <stClient> vClients = LoadClientsDataFromFile (ClientsFileName);

    UpdateClientByAccountNumber (AccountNumber, vClients);
}

//5. Find Client
void ShowFindCLientScreen ()
{
    cout << "------------------------------" << endl;
    cout << "     Find Client Screen     " << endl;
    cout << "------------------------------" << endl;
    
    string AccountNumber = ReadClientNumber();
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber,vClients,Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with account number[" << AccountNumber << "] is not found!";
}

//6. Transactions
void GoBackToTranactionMenu ()
{
    cout << "Press any key to go back to Transaction menu..." << endl;
    system("pause>0");
    ShowTransactionScreen();
}
short ReadTransactionOption ()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

    // A. Deposite
double ReadDepositeAmount ()
{
    double Deposite;
    cout << "Enter Amount to deposite: ";
    cin >> Deposite;
    return Deposite;
}
bool DepositeBalanceToClientByAccountNumber (string AccountNumber,double Amount,vector <stClient> &vClients)
{
    char choice = 'n';
    cout << "are you sure you want to deposite (y/n) ? ";
    cin >> choice;
    if (choice == 'y' || choice =='Y')
    {
        for (stClient &C : vClients)
        {
            if (AccountNumber == C.AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveChangesToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully, New Balance: " << C.AccountBalance << endl; 
                return true;
            }
        }
    }
            return false;
}
void ShowDepositeScreen ()
{
    stClient Client;
    cout << "\n------------------------------" << endl;
    cout << "     Deposite Screen     " << endl;
    cout << "------------------------------" << endl;
    
    string AccountNumber = ReadClientNumber();
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    
    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "Please enter deposit amount? ";
    cin >> Amount;
    
    DepositeBalanceToClientByAccountNumber (AccountNumber,Amount, vClients);

}

    // B. Withdraw
double ReadWithrawAmount ()
{
    double Withdraw;
    cout << "Enter Amount to Withdraw: ";
    cin >> Withdraw;
    return Withdraw;
}
void ShowWithdrawScreen ()
{
    cout << "\n------------------------------" << endl;
    cout << "     Withdraw Screen     " << endl;
    cout << "------------------------------" << endl;

    stClient Client;
    string AccountNumber = ReadClientNumber();
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    
    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "Please enter withdraw amount? ";
    cin >> Amount;

    while (Amount > Client.AccountBalance)
    {
        cout << "Amount Exeeds the balance, you can withdraw up to " << Client.AccountBalance << endl;
        cout << "Please enter another amount: ";
        cin >> Amount;
    }
 //                                                               VVV
    DepositeBalanceToClientByAccountNumber (AccountNumber,Amount * -1, vClients);
}

    // C. Total Balances
void PrintCLientRecordBalanceLine (stClient StructClient)
{
    cout << "| " << left << setw(15) << StructClient.AccountNumber ;
    cout << "| " << left << setw(25) << StructClient.Name;
    cout << "| " << left << setw(15) << StructClient.AccountBalance << " |";

}
void ShowTotalBalances ()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    double Sum = 0;
    cout << "\n------------------------------" << endl;
    cout << "     Balances Screen          " << endl;
    cout << "------------------------------" << endl;
    cout << "\n\t\t\t\t Clients list (" << vClients.size() << ")\t\t\t\t\n";
    cout << "__________________________________________________"
         << "_____________" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(25) << "Name";
    cout << "| " << left << setw(10) << "Account Balance |";

    cout << endl;
    cout << "__________________________________________________"
         << "_____________" << endl;
    for (stClient C : vClients)
    {
        Sum += C.AccountBalance;
        PrintCLientRecordBalanceLine(C);
        cout << endl;
    }
    cout << "__________________________________________________"
         << "_____________" << endl;
    
    cout << "\t\t\tTotal Balance: " << Sum << endl;
}
void PerformTranactionOptions (enTransactionsOptions TransactionsOption)
{
    switch (TransactionsOption)
    {
        case enTransactionsOptions::eDeposit:
            system("cls");
            ShowDepositeScreen();
            GoBackToTranactionMenu();
            break;
        case enTransactionsOptions::eWithdraw:
            system("cls");
            ShowWithdrawScreen();
            GoBackToTranactionMenu();
            break;
        case enTransactionsOptions::eTotalBalances:
            system("cls");
            ShowTotalBalances();
            GoBackToTranactionMenu();
            break;
        case enTransactionsOptions::eBack:
            system("cls");
            ShowMainMenu();
            break;
    }
}
void ShowTransactionScreen ()
{
    cout << "\n------------------------------" << endl;
    cout << "     Transaction Screen       " << endl;
    cout << "------------------------------" << endl;
    cout << "\t[1] Deposit\n";
    cout << "\t[2] Withdraw\n";
    cout << "\t[3] Total Balances\n";
    cout << "\t[4] Back\n";
    PerformTranactionOptions((enTransactionsOptions)ReadTransactionOption());
}
// 7. exit
void ShowEndScreen ()
{
    cout << "------------------------------" << endl;
    cout << "     Program Ends 8-)     " << endl;
    cout << "------------------------------" << endl;
}
short ReadMainMenuOption ()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

void GoBackToMainMenu ()
{
    cout << "\nPress any key to continue...\n";
    system("pause>0");
    ShowMainMenu();
}
void PerformMainMenuOptions (enMainMenuOptions MainMenuOption)
{

    switch (MainMenuOption)
    {
    case enMainMenuOptions::eShowClientList:
    
        system ("cls");
        PrintClientsList(ClientsFileName);
        GoBackToMainMenu();
        break;
     
    case enMainMenuOptions::eAddClient:
    
        system ("cls");
        AddNewCliantToFileScreen();
        GoBackToMainMenu();
        break;
     
    case enMainMenuOptions::eDeleteClient:
    
        system ("cls");
        ShowDeleteClientControlScreen();
        GoBackToMainMenu();
        break;
     
    case enMainMenuOptions::eUpdateClientInfo:
    
        system ("cls");
        ShowUpdateClientControlScreen();
        GoBackToMainMenu();
        break;
     
    case enMainMenuOptions::eFindCLient:
    
        system ("cls");
        ShowFindCLientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eTransactions:
        system("cls");
        ShowTransactionScreen();
        break; 
    case enMainMenuOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    
    default:
        break;
    
    }
}
void ShowMainMenu ()
{
    cout << "__________________________________" << endl;
    cout << "               Menu               " << endl;
    cout << "__________________________________" << endl;
    cout << "\t[1] Show client list\n";
    cout << "\t[2] Add Client\n";
    cout << "\t[3] Delete Client\n";
    cout << "\t[4] Update Client\n";
    cout << "\t[5] Find Client\n";
    cout << "\t[6] Transactions\n";
    cout << "\t[7] Exit\n";
    cout << "__________________________________\n" << endl;
    cout << "Enter Choice (1 to 6): ";
    PerformMainMenuOptions((enMainMenuOptions)ReadMainMenuOption());
}
int main ()
{
    ShowMainMenu();
    system("pause>0");
}