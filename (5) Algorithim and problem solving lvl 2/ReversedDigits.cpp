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

void ReversedNumber (int number)
{
    int Remainder = 0; int ReversedNumber = 0;
    while (number > 0)
    {
        Remainder = number % 10; // ex: 1234 % 10 => 4   (will print it later)
        number /= 10; //                1234 / 10 => 123 (last digit removed)
        cout << Remainder << endl;
    }
}

int main ()
{
     ReversedNumber(ReadPositiveNumber("Enter number?"));
}