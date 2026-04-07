#include <iostream>
#include<string>
using namespace std;

float ReadPostiveNumber (string massege)
{
    float number = 0;
    do 
    {
        cout << massege << endl;
        cin >> number;
    } while (number < 0);
    return number;
}

float MonthlyInstallment (float LoanAmount, float TotalMounthsToPay)
{
    return LoanAmount / TotalMounthsToPay;
}

int main ()
{
    float LoanAmount = ReadPostiveNumber("Enter Loan Amount?");
    float TotalMounthsToPay = ReadPostiveNumber("Enter Total Mounths To Pay");

    cout << "Monthly Installment: " << MonthlyInstallment (LoanAmount,TotalMounthsToPay)
    << endl;
    return 0;
}