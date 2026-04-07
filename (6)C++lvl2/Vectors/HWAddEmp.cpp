#include <iostream>
#include<vector>
#include<string>

using namespace std;

struct stEmployeeInfo 
{
    string FirstNameOnly;
    int Age;
    double Salary;
};

void ReadEmpInfo (vector <stEmployeeInfo> & vEmployee)
{
    stEmployeeInfo stEmployee;
    char choice = 'Y';

    while (choice == 'y' || choice == 'Y')
    {
        cout << "\nEnter Employee Full Name : ";
        //getline(cin, stEmployee.FullName);
        cin >> stEmployee.FirstNameOnly;

        cout << "Enter Employee Age : ";
        cin >> stEmployee.Age;

        cout << "Enter Employee Salary : ";
        cin >> stEmployee.Salary;

        vEmployee.push_back(stEmployee);

        cout << "\ndo you want to add more employee? ";
        cin >> choice;
    }
}

void PrintEmployeeInfo (vector <stEmployeeInfo> vEmployee)
{
    cout << "\nEmployees: \n\n";
    for (stEmployeeInfo & stEmployee : vEmployee)
    {
        cout << "Name: " << stEmployee.FirstNameOnly << endl;
        cout << "Age: " << stEmployee.Age << endl;
        cout << "Salary: " << stEmployee.Salary << endl;

        cout << "\n";
    }
}

int main ()
{
    vector<stEmployeeInfo> vEmployee;
     ReadEmpInfo(vEmployee);
    PrintEmployeeInfo(vEmployee);

    return 0;
}