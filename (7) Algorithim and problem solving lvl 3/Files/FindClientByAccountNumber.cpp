// Find Cient on a file by client number 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber ;
    string PinCode ;
    string Name ;
    string PhoneNumber;
    double AccountBalance;
};

string ReadAccountNumber ()
{
    string AccountNumber ;
    cout << "Enter Account Number: ";
    cin >> AccountNumber;

    return AccountNumber;
}

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

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByNumberInFile (string AccountNumber, stClient &ClientFound)
{    
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (stClient Client : vClients) 
    {
        if (Client.AccountNumber == AccountNumber) 
        {
            ClientFound = Client;
            return true;
        }
    }
    return false;

}

int main ()
{
    stClient ClientFound;
    string AccountNumber = ReadAccountNumber();

    if (FindClientByNumberInFile(AccountNumber, ClientFound))
    {
        PrintClientCard(ClientFound);
    } 
    else 
    {
        cout << "Account Not Found!" << endl;
    }

    system ("pause>0");
    return 0;

}