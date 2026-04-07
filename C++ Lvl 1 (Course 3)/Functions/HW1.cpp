#include <iostream>
#include <string>
using namespace std;

void MyInformations ()
{
    string Name;
    int age;
    string country;
    string city;
    Name = "Suhaib Erinat";
    age = 18;
    country = "Palestine";
    city = "jericho";

    cout << "***************" << endl;
    cout << "Neme : " << Name << endl;
    cout << "age : " << age << endl;
    cout << "country : " << country << endl;
    cout << "city : " << city << endl;
    cout << "***************" << endl << endl;
}
void SqrtStars ()
{
    cout << "*********" << endl;
    cout << "*********" << endl;
    cout << "*********" << endl;
    cout << "*********" << endl << endl;
}
void ILoveProgramming ()
{
    cout << "I love programming!" << endl;
    cout << "I promise to be the best developer ever!" << endl;
    cout << "I know it will take some time to practice, but i will achieve my goal" << endl;
    cout << "best regards," << endl;
    cout << "Mohammed Abu-Hadhoud" << endl;
    cout << "4/6/2024" << endl;
    cout << "7:05 AM"<< endl << endl;
}
void LetterH()
{
    cout << "*    *" << endl;
    cout << "*    *" << endl;
    cout << "******" << endl;
    cout << "*    *" << endl;
    cout << "*    *" << endl << endl;
}
int main ()
{
    MyInformations();
    ILoveProgramming ();
    LetterH ();
    SqrtStars ();

return 0;
}