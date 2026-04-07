#include <iostream>

using namespace std;

class clsPerson
{
private:
    string _Firstname, _LastName;
    string address;
    short age;
public:
    // property set
    void setFirstName (string name)
    {
        _Firstname = name;
    }
    // property get
    string getFirstName() 
    {
        return _Firstname;
    }
    // property set
    void setLastName (string name)
    {
        _LastName = name;
    }
    // property get
    string getLastName ()
    {
        return _LastName;
    }
    // property get
    string getFullName ()
    {
        return _Firstname + " " + _LastName;
    }

};

int main ()
{
    clsPerson Person1;
    Person1.setFirstName("Suhaib");
    Person1.setLastName("Erinat");

    cout << "First name: " << Person1.getFirstName() << endl;
    cout << "Last name: " << Person1.getLastName() << endl;
    cout << "Full name: " << Person1.getFullName() << endl;

}