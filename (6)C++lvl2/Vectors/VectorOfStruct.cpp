#include<vector>
#include<iostream>
#include<string>

using namespace std;

struct stEmployeeInformation
{
    string First_Name = "";
    string Last_Name = "";
    float Salary = 0;
};

int main ()
{
    vector <stEmployeeInformation> vEmployees;

    stEmployeeInformation temporaryInformations;

    temporaryInformations.First_Name = "Suhaib";
    temporaryInformations.Last_Name = "Erniat";
    temporaryInformations.Salary = 5000;
    vEmployees.push_back(temporaryInformations); // <====

    // The information added to the vector now... Let's add more.

    temporaryInformations.First_Name = "Ahmad";
    temporaryInformations.Last_Name = "Mohammad";
    temporaryInformations.Salary = 5500.25;
    vEmployees.push_back(temporaryInformations); // <====

    // Print the informations using ranged loop :

    cout << "Employees vector: \n\n";

    for (stEmployeeInformation Employee : vEmployees)
    {
        cout << "First Name : " << Employee.First_Name  << endl;
        cout << "Last Name  : " << Employee.Last_Name << endl;
        cout << "Salalry    :" << Employee.Salary << endl << endl;
    }

}