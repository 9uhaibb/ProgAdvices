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

float TotalMounths (float LoanAmount, float MonthlyInstallment)
{
    return LoanAmount / MonthlyInstallment;
}

int main ()
{
    float LoanAmount = ReadPostiveNumber("Enter Loan Amount?");
    float MonthlyInstallment = ReadPostiveNumber("Enter Monthly Installment?");

    cout << "Total Mounth To Pay: " << TotalMounths (LoanAmount,MonthlyInstallment) << " Mounths"
    << endl;
    return 0;
}