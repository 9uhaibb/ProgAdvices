#include<iostream>
using namespace std;

struct stEmployee
{
    string Name;
    int Salary;
};


int main ()
{
    stEmployee Employee1;
    stEmployee *pointer;

    Employee1.Name = "Suhaib Erinat";
    Employee1.Salary = 5000;

    pointer = &Employee1;

    // printinig using pointer on structure :
    cout << pointer->Name << endl;
    cout << pointer->Salary << endl;

    stEmployee Employee2;

    Employee2.Name = "Ahmad";
    Employee2.Salary = 5000;

    pointer = & Employee2;

    // printinig using pointer :
    cout << pointer->Name << endl;
    cout << pointer->Salary << endl;





    


}