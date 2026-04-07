#include <iostream>
#include <string>
using namespace std;


struct stInfo
{
    string FirstName;
    string LastName;
};
stInfo ReadInfo () 
{
    stInfo info;
    cout << "Enter Your First Name : \n"; 
    cin >> info.FirstName;
    cout << "Enter Your Last Name : \n";
    cin >> info.LastName;
    return info;
}
string GetFullName (stInfo info)
{
    string FullName = "";
    FullName= info.FirstName + " " + info.LastName;
    return FullName;
}
void PrintFullName (string FullName)
{
    cout << "Your Full Name is: " << FullName << endl;
}
int main () 
{
PrintFullName(GetFullName(ReadInfo()));
}