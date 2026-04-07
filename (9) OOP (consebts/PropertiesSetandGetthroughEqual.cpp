#include <iostream>
using namespace std;

class clsPerson 
{
private:
    string _FirstName;
public:
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string getFirstName ()
    {
        return _FirstName;
    }

    //   Properties Set and Get through "="
    __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
};

int main ()
{
    clsPerson Person1;
    // normal
    Person1.setFirstName("Suhaib");
    cout << "First Name: " << Person1.getFirstName() << endl;

    // using Set and Get through "="
    Person1.FirstName = "Suhaib";
    cout << "First Name: " << Person1.FirstName << endl;
}