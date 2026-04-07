
#include <iostream>
#include<fstream>
#include <vector>
#include <iomanip>
#include<string>

using namespace std;

struct stClient
{
    string AccountNumber ;
    string PinCode ;
    string Name ;
    string PhoneNumber;
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

int main ()
{
    vector <stClient> VectorOfClients = LoadClientsDataFromFile (ClientsFileName);

    PrintAllvClientsElements (VectorOfClients);

    system("pause>0");
}