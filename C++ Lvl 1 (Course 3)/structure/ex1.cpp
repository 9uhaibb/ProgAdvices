#include <iostream>
using namespace std;



struct stContactInfo
{
    int phone;
    string email;
};
struct stAddress
{
    string city;
    int street;
};
struct stPerson
{
    string First_name;
    string Last_name;
        stAddress address;
        stContactInfo contactInfo;

};
int main () 
{
    stPerson person1;
    person1.First_name="Suhaib";
    person1.Last_name="Erinat";
    person1.address.city="Jericho";
    person1.address.street=90;
    person1.contactInfo.phone=0560000000;
    person1.contactInfo.email="ex@gmail.com";

    //u can cout what u want, ex :
    cout << person1.First_name << endl;
    // u can also add stPerson person2, 3 ,4...


}