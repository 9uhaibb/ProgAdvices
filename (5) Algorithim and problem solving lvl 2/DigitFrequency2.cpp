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

int SingleDigitFrequencyCount (int number, int digitToCheck)
{
    // we take the last digit to print it then remove it and repeat
    int frequency = 0;
    int Remainder = 0;
    while (number > 0)
    {
        Remainder = number % 10; // ex: 1234 % 10 => 4   (will print it later)
        number /= 10; //                1234 / 10 => 123 (last digit removed)
        if (Remainder == digitToCheck)
        {
            frequency ++;
        }
    }
    return frequency;
}

void PrintAllDigitFrequencyCount (int number)
{
    for (int i =0 ; i <= 9; i++)
    {
        int digitFrequency = 0;
        digitFrequency = SingleDigitFrequencyCount(number , i); // check all numbers 0 to 9.
        if (digitFrequency > 0) // reject(not print) all 0 frequencies.
        {
            cout << "Digit " << i << " Frequency is "
                 << digitFrequency << " Time(s).\n";
        }
    }
}

int main ()
{
    int number = ReadPositiveNumber ("Enter a number?");
    PrintAllDigitFrequencyCount(number);

}