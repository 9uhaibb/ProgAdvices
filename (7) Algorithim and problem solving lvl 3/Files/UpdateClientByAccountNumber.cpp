// Update Client by account number
/*steps
1. Read Account number (done)
2. load data from a file (in a vector form) (done)
3. search on the client to change
4.save changes to file
*/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double
    return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

//1.read the acc number to delete
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

//2.load data from a file (in a vector form)
vector<sClient> LoadCleintsDataFromFile (string FileName)
{
    fstream MyFile;
    vector <sClient> vClients;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

//3. search on the client to change
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
sClient ChangeClientRecord (string AccountNumber)
{
    sClient Client ;

    Client.AccountNumber = AccountNumber;    
    cout << "Enter Pin Code: ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name: ";
    getline(cin, Client.Name);
    
    cout << "Enter Phone Number: ";
    getline(cin, Client.Phone);
    
    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
    
}

//4.save changes to file
void SaveChangesToFile (string FileName, vector<sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out/*write mode*/);

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}

bool UpdateClientByAccountNumber (vector<sClient> &vClients, string AccountNumber)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients,Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this client?\n";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClient & C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    cout << "Updating client: " << AccountNumber << endl;
                    C = ChangeClientRecord(AccountNumber); // now the record data changed inside the vector
                    break;
                }
            }
            SaveChangesToFile(ClientsFileName, vClients);
            return true;
        }
    }
    
    return false;
}

int main()
{
    string AccountNumber = ReadClientAccountNumber();
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    
    if (UpdateClientByAccountNumber(vClients, AccountNumber))
    {
        cout << "Client updated Successfuly.";
    }
    else 
    {
        cout << "Account Not found!";
    }
}
