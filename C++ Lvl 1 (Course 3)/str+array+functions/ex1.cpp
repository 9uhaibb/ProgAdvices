#include <iostream>
using namespace std;

// read prosedure, using struct
// print prosedure usnig struct
// more than one persons so use array

struct strInfo
{
    string First_Name;
    string Last_Name;
    int age;
    int phone;
};

void ReadInfo(strInfo person[1])
{
    person[0].First_Name = "Suhaib";
    person[0].Last_Name = "Erinat";
    person[0].age = 18;
    person[0].phone = 05644444444;

    person[1].First_Name = "Mohammed";
    person[1].Last_Name = "Ahmad";
    person[1].age = 13;
    person[1].phone = 056666666;
}
void PrintInfo(strInfo person[1])
{
    cout << "********************\n";
    cout << "First Name : " << person[0].First_Name << endl;
    cout << "Last Name : " << person[0].Last_Name << endl;
    cout << "Age : " << person[0].age << endl;
    cout << "Phone : " << person[0].phone << endl;
    cout << "********************\n";
    cout << "********************\n";
    cout << "First Name : " << person[1].First_Name << endl;
    cout << "Last Name : " << person[1].Last_Name << endl;
    cout << "Age : " << person[1].age << endl;
    cout << "Phone : " << person[1].phone << endl;
}

int main()
{
    strInfo person[1];

    ReadInfo(person);
    PrintInfo(person);
}