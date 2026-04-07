#include<iostream>
#include<cmath>
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

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

enPrimeNotPrime CheckPrime (int number)
{
    int M = round(number / 2);
    for (int counter = 2; counter <= M;counter++)
    {
        if (number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void PrintPrimeNumberFrom1ToNType (int number)
{
    cout << "Prime Numbers From " << 1 << " To " << number;
    cout << " are: \n";
    for (int i = 1; i <= number ; i++)
    if (CheckPrime(i) == enPrimeNotPrime::Prime)
        cout << i << endl;
}

int main ()
{
    PrintPrimeNumberFrom1ToNType(ReadPositiveNumber("Enter Positive Number?"));
}