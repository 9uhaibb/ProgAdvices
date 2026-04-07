
#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <limits>


using namespace std;

class clsBankClient : public clsPerson
{
public:

    struct stTransferLogRecord
    {
        string DateTime;
        string SenderAccNum;
        string RecieverAccNum;
        double Amount;
        double SenderFinalBalance;
        double RecieverFinalBalance;
        string SenderUsername;
    };

private:
    
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNew = 2
    };
    
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool MarkForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                             vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static stTransferLogRecord _ConvertTransferLineToRecord (string Line, string Seperator = "#//#")
    {
        stTransferLogRecord TransferRecord;
        vector <string> vTransfersLog = clsString::Split(Line, Seperator);

        TransferRecord.DateTime = vTransfersLog[0];
        TransferRecord.SenderAccNum = vTransfersLog[1];
        TransferRecord.RecieverAccNum = vTransfersLog[2];
        TransferRecord.Amount = stod (vTransfersLog[3]);
        TransferRecord.SenderFinalBalance = stod (vTransfersLog[4]);
        TransferRecord.RecieverFinalBalance = stod (vTransfersLog[5]);
        TransferRecord.SenderUsername = vTransfersLog[6];

        return TransferRecord;

    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    
    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SavaClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::out);
        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkForDelete == false)
                {
                    // only write the records that are not marked for delete
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        // i already updated the client info using ReadClientInfo
        // the updated version is stored in the memory, but still old in the file

        // i need to reach the old version (in the file)
        // replace it with the new version (in the memory)
        // i can reach the updated version using *this pointer
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients) // & to go to the address directly, not creating a copy
        {
            if (C.AccountNumber() == (AccountNumber()))
            {
                C = *this; // C represent the data in the file
                break;
            }
        }
        _SavaClientsDataToFile(_vClients);
    }
    //
    static string ReadString()
    {
        string S;
        getline(cin >> ws, S);
        return S;
    }
    static double ReadDblNumber(string Errormessage)
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            // include limits
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormessage;
        }
        return Number;
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
           
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    string _PrepareTransferRecord (double Amount, clsBankClient Reciever,
    string Username, string Seperator = "#//#")
    {
        string TransferLine = "";   
        TransferLine += clsDate::GetSysDateAndTimeString() + Seperator;
        TransferLine += AccountNumber() + Seperator;
        TransferLine += Reciever.AccountNumber() + Seperator;
        TransferLine += to_string(Amount) + Seperator;
        TransferLine += to_string(GetAccountBalance())+ Seperator;
        TransferLine += to_string(Reciever.GetAccountBalance())+ Seperator;
        TransferLine += Username;

        return TransferLine;
    }

    void _RegisterTransferLog (double Amount, clsBankClient Reciever, string Username) // تسجيل بيانات المستخدم عند تسجيل الدخول
    {
        fstream RegisterLogFile;

        RegisterLogFile.open("TransferLog.txt", ios ::app | ios::out);

        if (RegisterLogFile.is_open())
        {
            string DataLine = _PrepareTransferRecord(Amount, Reciever, Username);

            RegisterLogFile << DataLine << endl;

            RegisterLogFile.close();
        }
    }


public:

    // takes base att + sub att
    // we pass the base att to sub att using base constructor
    clsBankClient(enMode Mode, string FirstName, string LastName,
                  string Email, string Phone, string AccountNumber, string PinCode,
                  float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    //__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    //__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // open the file -read Mode

        if (MyFile.is_open()) // if the file is open
        {
            string Line;
            while (getline(MyFile, Line)) // store from the file line by line inside (Line)
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line); // while storing convert the current line to object
                if (Client.AccountNumber() == AccountNumber)             // check the condition
                {
                    MyFile.close(); // if yes close the file
                    return Client;  // return the object
                }
            }
            MyFile.close(); // if there is no obj satisfies the condition, close the file and return empty obj
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber); // the Find method return an obj, empty if not found
        return (!Client1.IsEmpty());                                // if not empty return true
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExist
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResults::svFailedEmptyObject;
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNew:
        {
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExist;
            }
            else
            {
                _AddNew(); // add to the file
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        }
          default:
        // في حال حصلت قيمة غير متوقعة
        return enSaveResults::svFailedEmptyObject;
        }
    }

    static void ReadClientInfo(clsBankClient &Client) // & apply the changes on the original
    {
        cout << "\nEnter First Name: ";
        Client.SetFirstName(ReadString());

        cout << "\nEnter Last Name: ";
        Client.SetLastName(ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(ReadString());

        cout << "\nEnter Pin Code: ";
        Client.SetPinCode(ReadString());

        cout << "\nEnter Balance: ";
        Client.SetAccountBalance(ReadDblNumber("Invalid nubmer type, Try again"));
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete ()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient & C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C.MarkForDelete = true;
                break;
            }
        }
        _SavaClientsDataToFile(vClients);

        // now the obj still full, i need to make it empty
        *this = _GetEmptyClientObject();
        return true;
    }

    static vector <clsBankClient> GetClientsList ()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances ()
    {
        vector <clsBankClient> vCLients = _LoadClientsDataFromFile();
        double TotalBalances = 0;
        
        for (clsBankClient C : vCLients)
        {
            TotalBalances += C.GetAccountBalance();
        }

        return TotalBalances;
    }

     void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

   
    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
          _AccountBalance -= Amount;
          Save();
          return true;
        }
       
    }

    bool Transfer (double Amount, clsBankClient & Reciever, string Username)
    {
        if (Amount > GetAccountBalance())
        {
            return false;
        }

        Withdraw(Amount);
        Reciever.Deposit(Amount);
        _RegisterTransferLog(Amount, Reciever, Username);
        return true;
    }

    static vector <stTransferLogRecord> GetTransferLogList ()
    {
        vector <stTransferLogRecord> vTransfersList;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {
                TransferRecord = _ConvertTransferLineToRecord (Line);
                vTransfersList.push_back(TransferRecord);
            }

            MyFile.close();
        }
        return vTransfersList;
    }


    
};