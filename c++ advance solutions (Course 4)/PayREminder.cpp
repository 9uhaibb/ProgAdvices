#include <iostream>
using namespace std;

float ReadPositiveNumber (string massege)
{
    float number;
    cout << massege << endl;
    cin >> number;
    return number;
}

float CalculateRemaindear (float TotalBill, float TotalCashPaid)
{
    return TotalCashPaid - TotalBill;
}

int main ()
{
    float TotalBill = ReadPositiveNumber ("Please Enter Total Bill?");
    float TotalCashPaid = ReadPositiveNumber("Please Enter Total Cash Paid?");
    cout << endl <<"Total Bill = "<< TotalBill << endl << "Total Cash Paid = " <<  TotalCashPaid;
    cout << endl << "**********************\n";
    cout << "Remainder = " <<  CalculateRemaindear(TotalBill,TotalCashPaid);
}