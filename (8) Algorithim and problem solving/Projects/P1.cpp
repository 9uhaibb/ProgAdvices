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
    eFindCLient = 5, eTransactions = 6 ,eManegeUSers = 7,
    eExist = 8
};
enum enTransactionsOptions 
{
    eDeposit = 1, eWithdraw = 2,
    eTotalBalances = 3, eBack = 4
};
enum enMainMenuPermossions
{
    pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManegeUsers = 64 
};
enum enManegeUsersMenuOptions
{
    eListUsers = 1,
    eAddUser = 2,
    eDeleteUser = 3,
    eUpdateUserInfo = 4,
    eFindUser = 5,
    eBackToMainMenu = 6
};

struct sUser
{
    string Name;
    string Password;
    int Permissions;
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
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
const string UsersFileName = "Users.txt";

sUser CurrentUser;

void GoBackToMainMenu();
void GoBackToTranactionMenu();
void ShowMainMenu ();
void ShowTransactionScreen ();

void ShowFindCLientScreen();
void GoBackToFindClientScreen();

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

void ShowAccessDeniedMassege ()
{
    cout << "------------------------------" << endl;
    cout << "Access Denied,\nYou dont have permission to do this,\nPlease contact the admin" << endl;
    cout << "------------------------------" << endl;
}

bool CheckAccessPermossion (enMainMenuPermossions Permossion)
{
    if (CurrentUser.Permissions == enMainMenuPermossions::pAll)
        return true;
    if ((Permossion & CurrentUser.Permissions) == Permossion)
    // ex
    /* 00010010  (Permission to check)
    &  00110011  (Current User Permission)
    =  00010010 = true*/
        return true;
    else
        return false; 
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

bool FindClientByName(string ClientName, vector <stClient> vClients, stClient& Client)
{
    for (stClient C : vClients)
    {
        if (C.Name == ClientName)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

// 1. show Client List
void ShowAllClientsScreen (string FileName)
{
    if (!CheckAccessPermossion(enMainMenuPermossions::pListClients))
    {
        ShowAccessDeniedMassege();
        GoBackToMainMenu();
        return;
    }

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
    if (!CheckAccessPermossion(enMainMenuPermossions::pAddNewClient))
    {
        ShowAccessDeniedMassege();
        GoBackToMainMenu();
        return;
    }
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
    if (!CheckAccessPermossion(enMainMenuPermossions::pDeleteClient))
    {
        ShowAccessDeniedMassege();
        GoBackToMainMenu();
        return;
    }
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
    if (!CheckAccessPermossion(enMainMenuPermossions::pUpdateClient))
    {
        ShowAccessDeniedMassege();
        GoBackToMainMenu();
        return;
    }
    cout << "------------------------------" << endl;
    cout << "     Update Client Screen     " << endl;
    cout << "------------------------------" << endl;
    string AccountNumber = ReadClientNumber();
    vector <stClient> vClients = LoadClientsDataFromFile (ClientsFileName);

    UpdateClientByAccountNumber (AccountNumber, vClients);
}

//5. Find Client

enum enFindClientOptions {
    eName = 1, eAccountNumber = 2, eBalanceBiggerThanValue = 3, eBalanceLessThanValue = 4
};

short ReadFindCLientOption ()
{
    cout << "Choose what do you want to do? [1 to 3]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}
void PerformFindClientOptions (enFindClientOptions FindClientOption)
{
    switch (FindClientOption)
    {
        case enFindClientOptions::eName:
            system("cls");
            cout << "Find client by name will be here..\n";
            GoBackToFindClientScreen();
            break;
        case enFindClientOptions::eAccountNumber:
            system("cls");
            //FindClientByAccNumber(AccountNumber);
            //GoBackToFindUSderScfreen();
            break;
        case enFindClientOptions::eBalanceBiggerThanValue:
            system("cls");
            //FindClientByBalanceBiggerThan(value);
            //GoBack..
            break;
        case enFindClientOptions::eBalanceLessThanValue:
            system("cls");
            //FindClientByBalanceLessThan(value);
            //GoBack..
            break;
    }
}

void GoBackToFindClientScreen ()
{
    cout << "Press any key to go back to Transaction menu..." << endl;
    system("pause>0");
    ShowFindCLientScreen();
}
void ShowFindCLientScreen ()
{
    if (!CheckAccessPermossion(enMainMenuPermossions::pUpdateClient))
    {
        ShowAccessDeniedMassege();
        GoBackToMainMenu();
        return;
    }
    cout << "------------------------------" << endl;
    cout << "     Find Client Screen     " << endl;
    cout << "------------------------------" << endl;
    cout << "\tSearch by:\n";
    cout << "\t[1] Name\n";
    cout << "\t[2] Account Number\n";
    cout << "\t[3] Balance > value\n";
    cout << "\t[4] Balance < value\n";

    cout << "__________________________________\n" << endl;
    PerformFindClientOptions((enFindClientOptions)ReadFindCLientOption());
    
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    stClient Client;
    
    string AccountNumber = ReadClientNumber();
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
    if (!CheckAccessPermossion(enMainMenuPermossions::pListClients))
    {
        ShowAccessDeniedMassege();
        GoBackToMainMenu();
        return;
    }
    
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
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}
 //////////////////////////////////
 /// Users code starts here //////
/////////////////////////////////
void GoBackToManegeUsersMenu();
void ShowManegeUsersMenu();

sUser ConvertUserLineDataToRecord(string LineData, string Seperator = "#//#")
{
    sUser User;
    vector<string> vUsers;

    vUsers = SplitString(LineData, Seperator);

    User.Name = vUsers[0];
    User.Password = vUsers[1];
    User.Permissions = stoi(vUsers[2]);

    return User;
}
string ConvertUserRecordToLine(sUser User, string Seperator = "#//#")
{
    string DataLine;
    DataLine += User.Name + Seperator;
    DataLine += User.Password + Seperator;
    DataLine += to_string(User.Permissions);
    return DataLine;
}
vector<sUser> LoadUsersDataFromFile(string FileName)
{
    vector<sUser> vUsers;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertUserLineDataToRecord(Line);

            vUsers.push_back(User);
        }

        MyFile.close();
    }

    return vUsers;
}
void PrintSingleUser(sUser User)
{
    cout << "| " << left << setw(15) << User.Name;
    cout << "| " << left << setw(10) << User.Password;
    cout << "| " << left << setw(25) << User.Permissions;
}
void PrintUserCard(sUser User)
{
    cout << "\nThe following are the User details:\n";
    cout << "\nUsername: " << User.Name;
    cout << "\nPassword: " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << endl;
}
bool FindUserByUsername(string Username)
{
    vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for (sUser U : vUsers)
    {
        if (Username == U.Name)
        {
            return true;
        }
    }
    return false;
}
bool FindUserByUsernameAndPassword (string Username, string Password, sUser& User)
{
    vector <sUser> vUsers = LoadUsersDataFromFile (UsersFileName);

    for (sUser U : vUsers)
    {
        if (U.Name == Username && U.Password == Password)
        {
            User = U;
            return true;
        }
    }
    return false;
}
bool isCorrectPassword(string Username, string Password)
{
    vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for (sUser &U : vUsers)
    {
        if (U.Name == Username && U.Password == Password)
            return true;
    }
    return false;
}
vector<sUser> SavevUsersDataToFile(string FileName, vector<sUser> vUsers)
{
    fstream MyFile;
    string DataLine;
    MyFile.open(FileName, ios::out); // overwrite
    if (MyFile.is_open())
    {

        for (sUser &U : vUsers) // U by reff
        {
            if (U.MarkForDelete == false)
            {
                DataLine = ConvertUserRecordToLine(U);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vUsers; // we edit the file context using it
}

int ReadPermissionsToSet ()
{
    int Permissions = 0;
    char Answer = 'n';

    cout << "\nDo you want to give full access? (y/n)? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1; // full access
    }

    cout << "\nDo you want to give access to : \n";

        cout << "\nShow Clients List? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pListClients;

        cout << "\nAdd new client? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pAddNewClient;

        cout << "\nDelete client? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pDeleteClient;

        cout << "\nUpdate client? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pUpdateClient;

        cout << "\nFind client? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pFindClient;

        cout << "\nPerform transactions? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pTransactions;

        cout << "\nManage users? (y/n) "; cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissions += enMainMenuPermossions::pManegeUsers;

    return Permissions;
}

sUser ReadNewUser()
{
    sUser User;
    cout << "Enter Username: ";
    getline(cin >> ws, User.Name);

    while (FindUserByUsername(User.Name))
    {
        cout << "User with [" << User.Name << "] already exist, enter another one.\n";
        getline (cin >> ws, User.Name);
    }

    cout << "Enter Password: ";
    getline(cin, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;

}
// 1. show Users List

void ShowALlUsersScreen ()
{
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    
    cout << "\n\t\t\t\t Clients list (" << vUsers.size() << ")\t\t\t\t\n";
    cout << "__________________________________________________"
         << "______________________________________" << endl;

    cout << "| " << left << setw(15) << "Username";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(25) << "Permissions";

    cout << endl;
    cout << "__________________________________________________"
         << "______________________________________" << endl;

    for (sUser U : vUsers)
    {
        PrintSingleUser(U);
        cout << endl;
    }
    cout << "__________________________________________________"
         << "______________________________________" << endl;
}

void ShowListUsersScreen(string FileName)
{
    vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    ShowALlUsersScreen();
}
// 2. add User
void AddNewUser()
{
    sUser User;
    User = ReadNewUser();
    AddLineToFile(UsersFileName, ConvertUserRecordToLine(User));
}
void AddNewUsers ()
{
    char AddMore = 'Y';
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    do
    {
        cout << "Adding new User:\n\n";

        AddNewUser();
        cout << "\nUser Added Successfully, do you want to add more?\n";
        cin >> AddMore;
    } while (AddMore == 'y' || AddMore == 'Y');
}
void ShowAddNewUserScreen()
{
    system("cls");
    cout << "------------------------------" << endl;
    cout << "     Adding User Screen     " << endl;
    cout << "------------------------------" << endl;

    AddNewUsers();
}

// 3. delete User
bool FindUserByName(string Username, vector<sUser> vUsers, sUser &User)
{
    for (sUser U : vUsers)
    {
        if (U.Name == Username)
        {
            User = U;
            return true;
        }
    }
    return false;
}
string ReadUsername()
{
    cout << "Enter Username: ";
    string s;
    cin >> s;
    return s;
}
string ReadPassword()
{
    cout << "Enter Password: ";
    string s;
    cin >> s;
    return s;
}

bool MarkUserForDeleteByName(string Username, vector<sUser> &vUsers)
{
    for (sUser &U : vUsers)
    {
        if (U.Name == Username)
        {
            U.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
bool DeleteUserByUsername(string Username, vector<sUser> &vUsers)
{
    sUser User;
    char Answer = 'n';
    
    if (FindUserByName(Username, vUsers, User))
    {
        if (User.Permissions == -1)
        {
            cout << "Error: You cannot delete the Admin user!\n";
            return false;
        }

        PrintUserCard(User);
        cout << "\nAre You Sure you want to delete this User? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            MarkUserForDeleteByName(Username, vUsers);
            SavevUsersDataToFile(UsersFileName, vUsers);
            vUsers = LoadUsersDataFromFile(UsersFileName);
            cout << "Clinet Deleted Successfully.\n";
            return true;
        }
        else
        {
            system("cls");
            cout << "\nReturning to the main menu...\n";
            GoBackToManegeUsersMenu(); // العودة للقائمة الرئيسية
            return false;
        }
    }
    else
    {
        system("cls");
        cout << "\nUser with Name (" << Username << ") is Not Found!";
        cout << "\nReturning to the main menu...\n";
        GoBackToManegeUsersMenu(); // العودة للقائمة الرئيسية
        return false;
    }
}
void ShowDeleteUserControlScreen()
{
    cout << "------------------------------" << endl;
    cout << "     Delete User Screen     " << endl;
    cout << "------------------------------" << endl;
    string Username = ReadUsername();
    
    vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    DeleteUserByUsername(Username, vUsers);
}

// 4. Update User
bool MarkUserForUpdateByUsername(string Username, vector<sUser> &vUsers)
{
    for (sUser &U : vUsers)
    {
        if (U.Name == Username)
        {
            U.MarkForUpdate = true;
            return true;
        }
    }
    return false;
}
sUser ChangeUserRecord(string Username)
{
    sUser User;

    User.Name = Username;


    User = ReadNewUser();

    return User;
}
void SaveChangesToFile(string FileName, vector<sUser> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out /*write mode*/);

    if (MyFile.is_open())
    {
        for (sUser C : vUsers)
        {
            MyFile << ConvertUserRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}
bool UpdateUserByUsername(string Username, vector<sUser> &vUsers)
{
    sUser User;
    char Answer = 'n';
    if (FindUserByName(Username, vUsers, User))
    {
        PrintUserCard(User);
        cout << "\nAre You Sure you want to update this User? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            for (sUser &C : vUsers)
            {
                if (C.Name == Username)
                {
                    cout << "Updating User: " << Username << endl;
                    C = ChangeUserRecord(Username);
                    break;
                }
            }
            SaveChangesToFile(UsersFileName, vUsers);
            cout << "User updated successfully!\n";
            return true;
        }
        else
        {
            system("cls");
            cout << "\nReturning to the main menu...\n";
            GoBackToManegeUsersMenu(); // العودة للقائمة الرئيسية
            return false;
        }
    }
    else
    {
        system("cls");
        cout << "\nUser with Account Number (" << Username << ") is Not Found!";
        cout << "\nReturning to the main menu...\n";
        GoBackToManegeUsersMenu(); // العودة للقائمة الرئيسية
        return false;
    }
}
void ShowUpdateUserControlScreen()
{
    cout << "------------------------------" << endl;
    cout << "     Update User Screen     " << endl;
    cout << "------------------------------" << endl;
    string Username = ReadUsername();
    vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    UpdateUserByUsername(Username, vUsers);
}

// 5. Find User
void ShowFindUserScreen()
{
    cout << "------------------------------" << endl;
    cout << "     Find User Screen     " << endl;
    cout << "------------------------------" << endl;

    string Username = ReadUsername();
    vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    sUser User;

    if (FindUserByName(Username, vUsers, User))
        PrintUserCard(User);
    else
        cout << "\nUser with account number[" << Username << "] is not found!";
}

// 7. exit
short ReadManegeUsersMenuOption()
{
    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

void GoBackToManegeUsersMenu()
{
    cout << "\nPress any key to continue...\n";
    system("pause>0");
    ShowManegeUsersMenu();
}
void PerformManegeUsersMenuOptions(enManegeUsersMenuOptions ManegeUsersMenuOption)
{
    switch (ManegeUsersMenuOption)
    {
    case enManegeUsersMenuOptions::eListUsers:
        system("cls");
        ShowListUsersScreen(UsersFileName);
        GoBackToManegeUsersMenu();
        break;

    case enManegeUsersMenuOptions::eAddUser:

        system("cls");
        ShowAddNewUserScreen();
        GoBackToManegeUsersMenu();
        break;

    case enManegeUsersMenuOptions::eDeleteUser:

        system("cls");
        ShowDeleteUserControlScreen();
        GoBackToManegeUsersMenu();
        break;

    case enManegeUsersMenuOptions::eUpdateUserInfo:

        system("cls");
        ShowUpdateUserControlScreen();
        GoBackToManegeUsersMenu();
        break;

    case enManegeUsersMenuOptions::eFindUser:

        system("cls");
        ShowFindUserScreen();
        GoBackToManegeUsersMenu();
        break;

    case enManegeUsersMenuOptions::eBackToMainMenu:
        system("cls");
        GoBackToMainMenu();
        break;

    default:
        break;
    }
}
void ShowManegeUsersMenu()
{
    system("cls");
    cout << "__________________________________" << endl;
    cout << "         Manege Users Menu        " << endl;
    cout << "__________________________________" << endl;
    cout << "\t[1] Show User list\n";
    cout << "\t[2] Add User\n";
    cout << "\t[3] Delete User\n";
    cout << "\t[4] Update User\n";
    cout << "\t[5] Find User\n";
    cout << "\t[7] Back to Main Menu\n";
    cout << "__________________________________\n"
         << endl;
    cout << "Enter Choice (1 to 7): ";
    PerformManegeUsersMenuOptions((enManegeUsersMenuOptions)ReadManegeUsersMenuOption());
}
bool CheckLoginInfo(const string &Username, const string &Password, const vector<sUser> &vUsers)
{
    for (const sUser &U : vUsers)
    {
        if (Username == U.Name && Password == U.Password)
        {
            return true;
        }
    }
    return false;
}

bool LoadUserInfo (string Username, string Password)
{
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
        return true;
    else
        return false;
}
void Login()
{
    bool LoginFailed = false;
    string Username, Password;

    do
    {
        system ("cls");

        cout << "__________________________________" << endl;
        cout << "           Login Screen           " << endl;
        cout << "__________________________________" << endl;

        if (LoginFailed)
            cout << "Invalid Username/Password!\n";
        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        LoginFailed = !LoadUserInfo(Username, Password);

    } while (LoginFailed);
    
    ShowMainMenu();
}
void GoBackToMainMenu ()
{
    cout << "\nPress any key to continue...\n";
    system("pause>0");
    ShowMainMenu();
}

void PerformMainMenuOptions(enMainMenuOptions MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enMainMenuOptions::eShowClientList: // 1

        system("cls");
        ShowAllClientsScreen(ClientsFileName);
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eAddClient: // 2

        system("cls");
        AddNewCliantToFileScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eDeleteClient: // 4

        system("cls");
        ShowDeleteClientControlScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eUpdateClientInfo: // 8

        system("cls");
        ShowUpdateClientControlScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eFindCLient: // 16

        system("cls");
        ShowFindCLientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eTransactions: // 32

        system("cls");
        ShowTransactionScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eManegeUSers: // 64

        system("cls");
        ShowManegeUsersMenu();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eExist:
        system("cls");
        Login();
        break;

    default:
        break;
    }
}
void ShowMainMenu()
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
    cout << "\t[7] Menege Users\n";
    cout << "\t[8] Logout\n";
    cout << "__________________________________\n" << endl;
    cout << "Enter Choice (1 to 8): ";

    PerformMainMenuOptions((enMainMenuOptions)ReadMainMenuOption());
}
int main ()
{
    Login();
    system("pause>0");
}