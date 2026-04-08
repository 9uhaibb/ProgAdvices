#include <iostream>
#include <vector>
#include <fstream>
#include<string>

using namespace std;

string ClientsFileName = "Clients.txt";

enum enATMOptions
{
    QuickDraw = 1, NormalWithDraw = 2,
    Deopsite = 3, CheckBalance = 4,
    Logout = 5
};

struct sClient 
{
    string AccountNumber ;
    string PinCode ;
    string Name ;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
};

sClient CurrentClient;

void Login();

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

sClient ConvertLineDataToRecord (string LineData, string Seperator = "#//#")
{
    sClient Client;
    vector <string> vClientData;

    vClientData = SplitString(LineData, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //casting from string to double

    return Client;
}
string ConvertRecordToLine (sClient Client, string Seperator = "#//#")
{
    string DataLine;
    DataLine += Client.AccountNumber + Seperator;
    DataLine += Client.PinCode + Seperator;
    DataLine += Client.Name + Seperator;
    DataLine += Client.PhoneNumber + Seperator;
    DataLine += to_string(Client.AccountBalance);
    return DataLine;
}
vector <sClient> LoadClientsDataFromFile (string FileName)
{
    vector <sClient> VectorOfClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClient StructClient;

        while (getline(MyFile, Line))
        {
            StructClient = ConvertLineDataToRecord(Line);

            VectorOfClients.push_back(StructClient);
        }

        MyFile.close();
    }

    return VectorOfClients;

}

bool FindClientByNumberInFile(string AccountNumber)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {
        if (AccountNumber == C.AccountNumber)
        {
            return true;
        }
    }
    cout << "Account [" << AccountNumber << "] is not exist!"; 
    return false;
}

bool CheckPinCode (sClient Client, string PinCode, string AccountNumber)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for ( sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
            return true;
    }
    return false;
}

vector <sClient> SavevClientsDataToFile (string FileName, vector<sClient> vCLients)
{
    fstream MyFile;
    string DataLine;
    MyFile.open(FileName, ios::out); // overwrite
    if (MyFile.is_open())
    {

        for (sClient &C : vCLients) // C by reff
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

sClient ReadClient ()
{
    cout << "Enter Account Number: ";
    sClient Client;
    cin >> Client.AccountNumber; 
    while (!FindClientByNumberInFile(Client.AccountNumber))
    {
        cout << "\nClinet with [" << Client.AccountNumber << "] already exist!\nEnter anothe account number: ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter Pin Code: ";
    cin >> Client.PinCode;
    while (!CheckPinCode(Client, Client.PinCode, Client.AccountNumber))
    {
        cout << "Invalid Account Number/Pin Code!\nTry Again,";
        cout << "Enter Pin Code: ";
        cin >> Client.PinCode;
    }
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    for (sClient &C : vClients)
    {
        if (C.AccountNumber == Client.AccountNumber)
        {
            return C; // إعادة العميل بكامل بياناته
        }
    }
    return Client;
}

void Login ();
void ShowATMMainMenuScreen ();
void GoBackToATMMainMenu ()
{   
    cout << "\nPress any key to continue...\n";
    system("pause>0");
    ShowATMMainMenuScreen ();
}

bool QuickWithdraw(string AccountNumber,short choice,vector <sClient> &vClients)
{
    short arrWithDrawChoice [] = {0, 20, 50, 100, 200, 400, 600, 800, 1000};
    
    cout << "Are you sure you want to withdraw " << arrWithDrawChoice[choice] << " ? (y/n) ";
    char YorN = 'n';
    if (YorN == 'Y' || YorN == 'n')
    {
        for (sClient & C : vClients)
        {
            if (C.AccountNumber == CurrentClient.AccountNumber)
            {
                C.AccountBalance -= arrWithDrawChoice[choice];

                CurrentClient.AccountBalance = C.AccountBalance;

                SavevClientsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully, New Balance: " << C.AccountBalance << endl; 
                return true;
            }
        }
    }
    return false;
}
void ShowQuickWithdrawScreen ()
{
    cout << "__________________________________" << endl;
    cout << "       Quick Withdraw Screen      " << endl;
    cout << "__________________________________" << endl;

    cout << "Choose Amount:\n";
    cout << "[1] 20. \t\t[2] 50.\n";
    cout << "[3] 100.\t\t[4] 200.\n";
    cout << "[5] 400.\t\t[6] 600.\n";
    cout << "[7] 800.\t\t[8] 1000.\n";
    cout << "[9] Exit.\n";

    short arrWithDrawChoice[] = {0, 20, 50, 100, 200, 400, 600, 800, 1000};
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    short choice;
    do {
        cout << "Enter choice [1 - 9]: ";
        cin >> choice;

        if (choice == 9)
            GoBackToATMMainMenu();

    } while (choice < 1 || choice > 9);

    double Amount = arrWithDrawChoice[choice];

    while (Amount > CurrentClient.AccountBalance)
    {
        cout << "Amount exceeds the balance, you can withdraw up to " << CurrentClient.AccountBalance << endl;
        cout << "Please enter another amount [1 - 9]: ";
        cin >> choice;

        if (choice == 9)
            GoBackToATMMainMenu();

        Amount = arrWithDrawChoice[choice];
    }

    QuickWithdraw(CurrentClient.AccountNumber, choice, vClients);
}

bool NormalyWithDraw (string AccountNumber, double Amount ,vector <sClient> &vClients)
{
    cout << "Current Amount: " << CurrentClient.AccountBalance << endl;
    char choice = 'n';

    cout << "Are you sure to Withdraw [" << Amount << "] ? (y/n) ? ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        for (sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance -= Amount;
                CurrentClient.AccountBalance = C.AccountBalance;

                SavevClientsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully, New Balance: " << C.AccountBalance << endl; 
                return true;
            }
        }
    }
    return false;
}
void ShowNormalWithDrawScreen ()
{
    cout << "__________________________________" << endl;
    cout << "      Normal Withdraw Screen      " << endl;
    cout << "__________________________________" << endl;

    double Amount;
    do 
    {
        cout << "Enter Amount: ";
        cin >> Amount;
    } while (Amount > CurrentClient.AccountBalance);

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    NormalyWithDraw(CurrentClient.AccountNumber, Amount,vClients);
    
}

bool Deposit (string AccountNumber, double Amount, vector <sClient> &vClients)
{
    char choice = 'n';
    cout << "Are you sure to deposit [" << Amount << "] ? (y/n) ? ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        for (sClient& C : vClients)
        {
            if (C.AccountNumber == CurrentClient.AccountNumber)
            {
                C.AccountBalance += Amount;

                CurrentClient.AccountBalance = C.AccountBalance;

                SavevClientsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully, New Balance: " << C.AccountBalance << endl; 
                return true;
            }
        }
    }
    return false;
}
void ShowDeopsiteScreen ()
{
    cout << "__________________________________" << endl;
    cout << "          Deposit Screen          " << endl;
    cout << "__________________________________" << endl;

    double Amount;
    do 
    {
        cout << "Enter Amount: ";
        cin >> Amount;

    } while (Amount < 0);

    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    Deposit(CurrentClient.AccountNumber, Amount, vClients);
}

void ShowCheckBalanceScreen ()
{
    cout << "__________________________________" << endl;
    cout << "       Check Balance Screen       " << endl;
    cout << "__________________________________" << endl;

    cout << CurrentClient.Name << " Balance is: " << CurrentClient.AccountBalance; 
}

void PerformShowATMMainMenuScreen (enATMOptions ATMOption)
{
    switch (ATMOption)
    {
        case enATMOptions::QuickDraw: // done
            ShowQuickWithdrawScreen();
            GoBackToATMMainMenu();
            break;

        case enATMOptions::NormalWithDraw: // done
            ShowNormalWithDrawScreen();
            GoBackToATMMainMenu();
            break;

        case enATMOptions::Deopsite:
            ShowDeopsiteScreen();
            GoBackToATMMainMenu();
            break;

        case enATMOptions::CheckBalance:
            ShowCheckBalanceScreen();
            GoBackToATMMainMenu();
            break;

        case enATMOptions::Logout:
            Login();
            GoBackToATMMainMenu();
            break;

        default:
            break;

    }
}

short ReadATMMainMenuOption ()
{
    cout << "Choose [1 - 5]: ";
    short n;
    cin >> n;
    return n;
}
void ShowATMMainMenuScreen ()
{
    system ("cls");
    cout << "__________________________________" << endl;
    cout << "          Main Menu Screen        " << endl;
    cout << "__________________________________" << endl;
    cout << "\t[1] Quick Withdraw\n";
    cout << "\t[2] Normal Withdra\n";
    cout << "\t[3] Deposite\n";
    cout << "\t[4] Check Balance\n";
    cout << "\t[5] Logout\n";

    PerformShowATMMainMenuScreen((enATMOptions)ReadATMMainMenuOption());
}

void Login ()
{   
    system ("cls");

    cout << "------------------------------" << endl;
    cout << "         Login Screen         " << endl;
    cout << "------------------------------" << endl;

    CurrentClient = ReadClient();

    ShowATMMainMenuScreen();
}

int main ()
{
    Login ();

    system ("pause>0");
    return 0;
}