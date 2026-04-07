#include <iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";
struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    string AccountBalance = "";
};

stClient ReadNewClient ()
{

    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter Account Pin Code? ";
    getline(cin, Client.PinCode);

    cout << "Enter Account Name? ";
    getline (cin, Client.Name);

    cout << "Enter Account Phone? ";
    getline(cin, Client.PhoneNumber);

    cout << "Enter Account Balance? ";
    getline(cin, Client.AccountBalance);

    return Client;
}

string ConvertRecordToLine (stClient Client, string Seperator = "#//#")
{
    string FinalString = "";

    FinalString += Client.AccountNumber + Seperator;
    FinalString += Client.PinCode + Seperator;
    FinalString += Client.Name + Seperator;
    FinalString += Client.PhoneNumber + Seperator;
    FinalString += Client.AccountBalance;

    return FinalString;
}

void AddDataLineToFile(string FileName, string DataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName,ConvertRecordToLine(Client,"#//#"));
}

void AddClients()
{
    char AddMore = 'Y';
    do
    {
        system ("cls"); // clear screen(terminal)
        cout << "Adding New Client:\n\n";

        AddNewClient ();
        cout << "\nClient added successfully, Do you want to add more?\n";
        cout << "if yes enter 'Y' or 'y', if No enter any buttom\n";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
    
}

int main ()
{
    cout << "Enter Client Data:\n";

    AddClients();

    system("pause>0");
}