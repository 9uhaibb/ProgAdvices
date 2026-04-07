#include<iostream>
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

int SingleDigitFrequencyCount (int number, int digit)
{
    // we take the last digit to print it then remove it and repeat
    int frequency = 0;
    int Remainder = 0;
    while (number > 0)
    {
        Remainder = number % 10; // ex: 1234 % 10 => 4   (to print it later)
        number /= 10; //                1234 / 10 => 123 (last digit removed)
        if (Remainder == digit)
        {
            frequency ++;
        }
    }
    return frequency;
}

int main()
{
    int number = ReadPositiveNumber("Enter a number?");
    int digit = ReadPositiveNumber("Enter a Digit?");
    cout << "Digit " << digit << " Frequency "
         << SingleDigitFrequencyCount(number,digit) << " Times.\n";
}