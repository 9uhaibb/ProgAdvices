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

bool CheckPerfect (int number)
{
    int sum = 0;
    for (int i =1; i< number ; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return number == sum; // if number = sum, return true (is perfect)
                                      //if no return false (not perfect)
    /* if (number == sum)
    return number or return sum
    */
}

void PrintPerfect (int number)
{
    if (CheckPerfect(number) == true)
    {
        cout << number << " is Perfect. ";
    }
    else 
    {
        cout <<number << " is Not Perfect.";
    }
}

int main ()
{
    PrintPerfect(ReadPositiveNumber("Enter a number?"));
}