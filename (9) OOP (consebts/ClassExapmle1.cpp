#include <iostream>

using namespace std;

class clsPerson
{
    int x;

    public:
    string FirstName; // Data Member
    string LastName; // Data Member

    string FullName () // Method (Function) Memeber
    {
        return FirstName + " " + LastName;
    }
    private:
    int Function1 ()
    {
        return 1;
    }
};

int main ()
{
    clsPerson Person1;
    Person1.FirstName = "Suhaib";
    Person1.LastName = "Erinat";

    cout << Person1.FullName() << endl;
}