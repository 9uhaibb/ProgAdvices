#include <iostream>
using namespace std;

float ReadPositiveNumber (string massege)
{
    float number;
    cout << massege << endl;
    cin >> number;
    return number;
}

float CalulateServiceAndTaxFees (float TotalBill)
{
    TotalBill *= 1.1;
    TotalBill *= 1.16;
    return TotalBill;
}

int main ()
{
    float TotalBill = ReadPositiveNumber("Please Enter Total BIll?");
    cout << "Total Bill = " << TotalBill;
    cout << endl << "Total Bill After Service and Tax Fees = " << CalulateServiceAndTaxFees(TotalBill);
}