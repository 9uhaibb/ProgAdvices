#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

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

void PrintNumberType (int number)
{
    switch (CheckPrime(number))
    {
        case enPrimeNotPrime::NotPrime:
        cout << "Not Prime.";
        break;
        case enPrimeNotPrime::Prime:
        cout << "Prime.";
        break;
    }
}

int main ()
{
    PrintNumberType(ReadPositiveNumber("Enter a Positive Number?"));
}

