#include<iostream>
using namespace std;
// Big To Small
int ReadPositiveNumber (string massege)
{
    int number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    }while (number <= 0 );
    return number;
}

void PrintNumberInPattern (int number)
{
    for (int j = number; j>= 1; j--) // loop to minusing when finish one number
    {
        for (int i = 1; i<=j; i++) // loop to print in times  
        {
            cout << j;
        }
     cout << endl;
    }
}

int main ()
{
    PrintNumberInPattern(ReadPositiveNumber("Enter a Number (1 to 9)?"));
}