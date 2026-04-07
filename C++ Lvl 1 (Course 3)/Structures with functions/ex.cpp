# include <iostream>
using namespace std;

struct strInfo
{
    string firstname;
    string lastname;
    int age;
    int phonenumber;
};

void ReadInfo (strInfo &info)// because i info here will be edited
{
    cout << "Enter your first name :\n";
    cin >> info.firstname;
    cout << "Enter your last name : \n";
    cin >> info.lastname;
    cout << "Enter your age : \n";
    cin >> info.age;
    cout << "Enter phone number : \n";
    cin >> info.phonenumber;
}
void PrintInfo (strInfo info)
{
    cout << "***************************" << endl;
    cout << "Your Name : " << info.firstname << " " << info.lastname<<".\n";
    cout << "Your age : " << info.age << endl;
    cout << "Your Phone Number : " << info.phonenumber << endl;
    cout << "***************************" << endl;
    
    
}
int main ()
{
    strInfo person1Info;
    ReadInfo(person1Info);
    PrintInfo(person1Info);
}