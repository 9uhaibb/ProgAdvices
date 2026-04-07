
#pragma once
#include <iostream>
#include <string>
#include"clsDate.h"
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <limits>
#include"clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
public :
    struct stLoginRegisterRecord 
    {
        string Username;
        string DateTime;
        string Password;
        int Permissions;
    };


private:
    enum enMode { EmptyMode = 0, UpdateMode = 1,AddNew = 2};

    enMode _Mode;
    string _Username;
    string _Password;
    int  _Permissions;
    bool _MarkForDelete = false;


    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
                             vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]),
                              stoi(vUserData[6]));
    }

    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord += User.GetFirstName() + Seperator;
        stUserRecord += User.GetLastName() + Seperator;
        stUserRecord += User.GetEmail() + Seperator;
        stUserRecord += User.GetPhone() + Seperator;
        stUserRecord += User.GetUsername() + Seperator;
        stUserRecord += clsUtil::EncryptText(User.GetPassword()) + Seperator;
        stUserRecord += to_string(User.GetPermossions());

        return stUserRecord;
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SavaUsersDataToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;

        MyFile.open("Users.txt", ios::out);
        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser C : vUsers)
            {
                if (C._MarkForDelete == false)
                {
                    // only write the records that are not marked for delete
                    DataLine = _ConvertUserObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        // i already updated the User info using ReadUserInfo
        // the updated version is stored in the memory, but still old in the file

        // i need to reach the old version (in the file)
        // replace it with the new version (in the memory)
        // i can reach the updated version using *this pointer
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser &C : _vUsers) // & to go to the address directly, not creating a copy
        {
            if (C.GetUsername() == (GetUsername()))
            {
                C = *this; // C represent the data in the file
                break;
            }
        }
        _SavaUsersDataToFile(_vUsers);
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
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
           
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    string _PrepareLoginRecord (string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSysDateAndTimeString() + Seperator;
        LoginRecord += _Username + Seperator;
        LoginRecord += clsUtil::EncryptText(_Password) + Seperator;
        LoginRecord += to_string(_Permissions);

        return LoginRecord;
    }

  static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord (string Line, string Seperator = "#//#")
  {
    stLoginRegisterRecord LoginRegisterRecord;
    vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);

    LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
    LoginRegisterRecord.Username = LoginRegisterDataLine[1];
    LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
    LoginRegisterRecord.Permissions =stoi( LoginRegisterDataLine[3]);

    return LoginRegisterRecord;
  }  

public:

    // takes base att + sub att
    // we pass the base att to sub att using base constructor
    clsUser(enMode Mode, string FirstName, string LastName,
                  string Email, string Phone, string Username, string Password,
                  int Permissions) : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkForDelete;
    }

    string GetUsername()
    {
        return _Username;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPermossions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermossions()
    {
        return _Permissions;
    }
    //__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

/* No ui related code inside object
    void Print()
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _Username;
        cout << "\nPassword    : " << _Password;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }
*/
    static clsUser Find(string Username)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // open the file -read Mode

        if (MyFile.is_open()) // if the file is open
        {
            string Line;
            while (getline(MyFile, Line)) // store from the file line by line inside (Line)
            {
                clsUser User = _ConvertLinetoUserObject(Line); // while storing convert the current line to object
                if (User.GetUsername() == Username)             // check the condition
                {
                    MyFile.close(); // if yes close the file
                    return User;  // return the object
                }
            }
            MyFile.close(); // if there is no obj satisfies the condition, close the file and return empty obj
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string Username, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUsername() == Username && User._Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string Username)
    {
        clsUser User1 = clsUser::Find(Username); // the Find method return an obj, empty if not found
        return (!User1.IsEmpty());                                // if not empty return true
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedUsernameExist = 2
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
            if (IsUserExist(_Username))
            {
                return enSaveResults::svFailedUsernameExist;
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
/* no related ui code inside object
    static void ReadUserInfo(clsUser &User) // & apply the changes on the original
    {
        cout << "\nEnter First Name: ";
        User.SetFirstName(ReadString());

        cout << "\nEnter Last Name: ";
        User.SetLastName(ReadString());

        cout << "\nEnter Email: ";
        User.SetEmail(ReadString());

        cout << "\nEnter Phone: ";
        User.SetPhone(ReadString());

        cout << "\nEnter Pin Code: ";
        User.SetPassword(ReadString());

        cout << "\nEnter Balance: ";
        User.SetAccountBalance(ReadDblNumber("Invalid nubmer type, Try again"));
    }
*/

    static clsUser GetAddNewUserObject(string Username)
    {
        return clsUser(enMode::AddNew, "", "", "", "", Username, "", 0);
    }

    bool Delete ()
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser & C : vUsers)
        {
            if (C.GetUsername() == _Username)
            {
                C._MarkForDelete = true;
                break;
            }
        }
        _SavaUsersDataToFile(vUsers);

        // now the obj still full, i need to make it empty
        *this = _GetEmptyUserObject();
        return true;
    }

    static vector <clsUser> GetUsersList ()
    {
        return _LoadUsersDataFromFile();
    }

    static vector <stLoginRegisterRecord> GetLoginRegistersList ()
    {
        vector <stLoginRegisterRecord> vLoginRegistersList;

        fstream MyFile;
        MyFile.open("LoginRegisters.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line); 
                vLoginRegistersList.push_back(LoginRegisterRecord);

            }

            MyFile.close();
        }
    return vLoginRegistersList;
    }

    enum enPermissions {FullAccess = -1, ListClients = 1 ,AddClients = 2,
                        DeleteClients = 4, UpdateClients = 8, FindClients = 16,
                        Tranactions = 32, ManageUsers = 64, ListLoginsRegister = 128};
// & = what exists in both sides.

// | = combine everything from both sides.
     bool CheckAccessPermission(enPermissions Permission) // 
    {  
        // is  Current User Pers = -1? yes : true
            
        // if No: false :

        // & = what exists in both sides.
        // is Permission & Current User Pers = Permission ? 

        //if yes > true, current user has the permission,
        // else > false           

        return (this->_Permissions == -1) || ((Permission & this->_Permissions) == Permission);
        
    }

    void LoginRegisters () // تسجيل بيانات المستخدم عند تسجيل الدخول
    {
        fstream RegisterLogFile;

        RegisterLogFile.open("LoginRegisters.txt", ios ::app | ios::out);

        if (RegisterLogFile.is_open())
        {
            string DataLine = _PrepareLoginRecord();

            RegisterLogFile << DataLine << endl;

            RegisterLogFile.close();
        }
    }


};