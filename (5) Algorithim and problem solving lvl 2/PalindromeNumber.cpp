// 1234 is Not a Palindrome Number.
// 12321 is a Palindrome Number.

#include<iostream>
#include <string>
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
        Remainder = number % 10; 
        number /= 10;
        ReversedNumber = ReversedNumber * 10 + Remainder; 
    }
    return ReversedNumber;
}

bool isPalindrome (int number)
{
    // if the number = the reversed number return true
    return number == ReversedNumber(number);
}

int main()
{
    if (isPalindrome (ReadPositiveNumber("Enter a Number?")))
    {
        cout << "is Palindrome.";
    }
    else 
    {
        cout << "is Not Palindrome.";
    }
}

