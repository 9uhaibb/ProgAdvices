#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string FileName = "Clients.txt";

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    double AccountBalance ;
};

stClient ReadClient ()
{
    stClient Client ;

    // usage of std::ws will extract all the whitespace character
    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);
    
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

string ConvertRecordToLine (stClient ClientToConvert, string Seperator = "#//#")
{
    string StringFinalString = "";

    StringFinalString += ClientToConvert.AccountNumber + Seperator;
    StringFinalString += ClientToConvert.PinCode + Seperator;
    StringFinalString += ClientToConvert.Name + Seperator;
    StringFinalString += ClientToConvert.PhoneNumber + Seperator;
    StringFinalString += to_string (ClientToConvert.AccountBalance);

    return StringFinalString;
}

void AddNewClient ()
{
    stClient Client;
    Client = ReadClient();
    AddLineToFile (FileName, ConvertRecordToLine(Client));
}

int main ()
{

    char AddMore = 'Y';

    do
    {
        system ("cls");
        cout << "Adding new Client:\n\n";

        AddNewClient ();
        cout << "\nClient Added Successfully, do you want to add more?\n";
        cin >> AddMore;
    } while (toupper(AddMore == 'Y'));
    

    system("pause>0");
}