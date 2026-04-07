#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    string AccountBalance = "";
};

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

void PrintStBankRecords (stClient Client)
{
    cout << "Your Account Number is: " << Client.AccountNumber << endl; 

    cout << "Your Account Pin Code is: "<< Client.PinCode << endl;

    cout << "Your Account Name is: "<< Client.Name << endl;

    cout << "Your Account Phone is: "<< Client.PhoneNumber << endl;

    cout << "Your Account Balance is: "<< Client.AccountBalance << endl;
}

int main ()
{
    // LineData = "AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance"
    string LineData = "12A#//#0290#//#Suhaib Erinat#//#0569125177#//#1500";

    stClient Client = ConvertLineDataToRecord(LineData,"#//#");

    cout << "Your Data Line:\n" << LineData << endl<< endl;
    cout << "Your Client Data:\n";
    PrintStBankRecords(Client);



}