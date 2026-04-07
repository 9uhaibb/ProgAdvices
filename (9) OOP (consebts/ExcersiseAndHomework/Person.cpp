#include<iostream>
using namespace std;

class clsPerson 
{

private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson (int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    };

    void setFirstName (string FirstName)
    {
        _FirstName = FirstName;
    }
    void setLastName (string LastName)
    {
        _LastName = LastName;
    }
    void setEmail (string Email)
    {
        _Email = Email;
    }
    void setPhone (int Phone)
    {
        _Phone = Phone;
    }

    string FirstName ()
    {
        return _FirstName;
    }
    string LastName ()
    {
        return _LastName;
    }
    string Email ()
    {
        return _Email;
    }
    string Phone ()
    {
        return _Phone;
    }
    int ID ()
    {
        return _ID;
    }
    string FullName ()
    {
        return _FirstName + " " + _LastName;
    }

    void SendEmail (string Subject, string Body)
    {
        cout << "The following massege sent successfully to email: " << _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << endl << endl;
    };
    void SendMassege (string Massege)
    {
        cout << "The following SMS sent successfully to Phone: " << _Phone << endl;
        cout << Massege << endl << endl;
    };

    void Print ()
    {
        cout << "Info\n";
        cout << "____________________\n";

        cout << "ID: " << _ID << endl;
        cout << "First Name: " << _FirstName << endl;
        cout << "Last Name: " << _LastName << endl;
        cout << "Full Name: " << FullName () << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone: " << _Phone << endl;

        cout << "____________________\n";
    }


};

int main () 
{
    clsPerson Person1 (10, "Suhaib", "Erinat", "suh@gmail.com", "123456879");
    Person1.Print();

    Person1.SendEmail("Hi", "This is suhaib");
    Person1.SendMassege("How are you?");

    system("pause>0");
    return 0;
}