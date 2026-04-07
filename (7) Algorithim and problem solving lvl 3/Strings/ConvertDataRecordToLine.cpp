#include <iostream>

using namespace std;

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

    cout << "Enter Account Number: ";
    getline(cin, Client.AccountNumber);
    
    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode);
    
    cout << "Enter Name: ";
    getline(cin, Client.Name);
    
    cout << "Enter PhoneNumber: ";
    getline(cin, Client.PhoneNumber);
    
    cout << "Enter AccountBalance: ";
    cin >> Client.AccountBalance;

    return Client;
    
}

string ConvertRecordToLine (stClient ClientToConvert, string Seperator)
{
    string StringFinalString = "";

    StringFinalString += ClientToConvert.AccountNumber + Seperator;
    StringFinalString += ClientToConvert.PinCode + Seperator;
    StringFinalString += ClientToConvert.Name + Seperator;
    StringFinalString += ClientToConvert.PhoneNumber + Seperator;
    StringFinalString += to_string (ClientToConvert.AccountBalance);

    return StringFinalString;
}

int main ()
{
    stClient Client;
    cout << "Enter Client Data:\n";
    Client = ReadClient();

    cout << "Line:\n";
    cout << ConvertRecordToLine(Client, "#//#");

    system("pause>0");
}