#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsString.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUser (clsUser User)
    {
        //cout << "Print User info will be here..\n";
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nPermissions : " << User.GetPermossions();
        cout << "\n___________________\n";
    }
public:
static void ShowDeleteUserScreen ()
{   
    _DrawScreenHeader("\tDelete User Screen");
    string Username = "";
    cout << "Deleteing User:\nEnter Username: ";
    Username = clsInputValiDate::ReadString();
//        Not
    while (!clsUser::IsUserExist(Username))
    {
        cout << "User is not exist, Please Enter Another: ";
        Username = clsInputValiDate::ReadString();
    }

    clsUser User = clsUser::Find(Username);
    _PrintUser(User);

    cout << "Are you sure you want to delete? (Y/N)";
    char choice = 'n';
    cin >> choice;

    if (toupper(choice) == 'Y')
    {
        // i want to make the delete method BOOL 
        // so it return true after deleting and saving the on file
        // after saving on the file i need to make the obj empty cuz it still full
        if (User.Delete() == true)// if Deleted 
        {
            cout << "\nUser Deleted Successfully :)\n";
            User.Print();
        }
    
        else 
        {
            cout << "\nError, User was not found\n";
        }
    }
}
};