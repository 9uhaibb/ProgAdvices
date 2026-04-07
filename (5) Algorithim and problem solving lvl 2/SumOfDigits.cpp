#include <iostream>
using namespace std;

int ReadPositiveNumber (string massege)
{
    int number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    }while (number <= 0);
    return number;
}

int SumDigits (int number)
{
    int Remainder = 0, Sum = 0;
    while (number > 0)
    {
        Remainder = number % 10; // ex : 1234 => 4
        Sum += Remainder;
        number /= 10;
    }
    return Sum;
}

void PrintSumDigits (int Result)
{
    cout << "Sum Of Digits = " << Result << endl;
}

int main ()
{
    PrintSumDigits(SumDigits(ReadPositiveNumber("Enter a number?")));
}