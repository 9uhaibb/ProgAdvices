#include<iostream>
#include <cmath>
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

int ReverseNumber (int number)
{
    float Remainder = 0,number2 = 0;
    while (number > 0)
    {
        Remainder = number % 10; 
        number /= 10; 
        number2 = number2 * 10 + Remainder;                
    }
    return number2;
}

void PrintReversedDigits (int number)
{
    float Remainder = 0;
    while (number > 0)
    {
        Remainder = number % 10; 
        number /= 10; //                
        cout << Remainder << endl;
    }
}

int main ()
{
    PrintReversedDigits(ReverseNumber(ReadPositiveNumber("Enter a number?")));
    // read the number   1234
    // reverse the number 4321
    /* reverse the digits 1
                          2
                          3
                          4
    */
}