#include <iostream>
using namespace std;

class clsEmployee
{
    int _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    string _Email;
    string _Phone;
    double _Salary;
    string _Department;

public:
    clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, double Salary, string Department)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Department = Department;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "The following massege sent successfully to email: " << _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << endl
             << endl;
    }
    void SendSMS(string TextMassege)
    {
        cout << "The following SMS sent successfully to Phone: " << _Phone << endl;
        cout << TextMassege << endl
             << endl;
    }
    void Print()
    {
        cout << "Info\n";
        cout << "____________________\n";

        cout << "ID: " << _ID << endl;
        cout << "First Name: " << _ID << endl;
        cout << "Last Name: " << _LastName << endl;
        cout << "Full Name: " << FullName() << endl;
        cout << "Title: " << _Title << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "Salary: " << _Salary << endl;
        cout << "Department: " << _Department << endl;
        cout << "____________________\n";
        cout << endl;
    }
};

int main ()
{
    clsEmployee Employee1 (10, "Ahmad", "Samer", "Engineer", "as@gmail.com", "38383929", 5000.00, "AA");
    Employee1.Print();

    Employee1.SendEmail ("Hi", "This is body");
    Employee1.SendSMS ("How are you?");

    system("pause>0");
    return 0;
}