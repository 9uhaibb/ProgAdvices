#include<iostream>
using namespace std;
// small to big
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

void PrintNumberPattern (int number)
{
    for (int j = 1; j<= number; j++) // loop to adding when finish one number
    {
        for (int i = 1; i<=j; i++) // loop to print in times (1 to number) 
        {
            cout << j;
        }
     cout << endl;
    }
}

int main ()
{
    PrintNumberPattern(ReadPositiveNumber("Enter a Positive Number?"));
}