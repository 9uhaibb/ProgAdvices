#include <iostream>
#include<fstream>
#include <vector>
#include<iomanip>
#include <string>

using namespace std;

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    double AccountBalance;
};

const string ClientsFileName = "Clients.txt";

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

vector <stClient> LoadClientDataFromFile(string FileName)
{
    vector <stClient> vClients;
    
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineDataToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }
    return vClients;
}

void PrintClientRecord (stClient Client)
{
    cout << "| "  << setw(15) << left << Client.AccountNumber;
    cout << "| "  << setw(10) << left << Client.PinCode;
    cout << "| "  << setw(40) << left << Client.Name;
    cout << "| "  << setw(12) << left << Client.PhoneNumber;
    cout << "| "  << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData (vector <stClient> vClients)
{
    cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "-------------------------------------------------------";
    cout << "---------------------------------------\n" << endl;

    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(40) << left  << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << endl;
    cout << "-------------------------------------------------------";
    cout << "---------------------------------------\n" << endl;

    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "-------------------------------------------------------";
    cout << "---------------------------------------\n" << endl;



}

int main ()
{
    vector <stClient> vClients = LoadClientDataFromFile(ClientsFileName/*const*/);

    PrintAllClientsData(vClients);

    system("pause>0");
}