#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber (string massege)
{
    int number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    } while (number < 0);

    return number;
}

int Factorial (int number)
{
    int F = 1;
    for (int counter = number; counter >= 1 ; counter--)
    {
        F *= counter;
    }
    return F;
}

int main ()
{
   cout << Factorial(ReadPositiveNumber("Enter a Positve number: ")); 
}