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

int ReversedNumber (int number)
{
    int Remainder = 0; int ReversedNumber = 0;
    while (number > 0)
    {
        Remainder = number % 10; // ex: 1234 % 10 => 4   (will print it later)
        number /= 10; //                1234 / 10 => 123 (last digit removed)
        ReversedNumber = ReversedNumber * 10 + Remainder; // RN     + R = RN
                                                          // 4*0    + 4 = 4
    }                                                     // 4*10   + 3 = 43
                                                          // 43*10  + 2 = 432
                                                          // 432*10 + 1 = 4321
}

int main ()
{
    cout << "Reversed Number is "
         <<ReversedNumber(ReadPositiveNumber("Enter number?"));
}