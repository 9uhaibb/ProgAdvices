#include<iostream>
#include<string>
using namespace std;
// A in ASCCI is 65
// This Prog Print Big To Small (Z to A)
int ReadPositiveNumber (string massege)
{
    int number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    }while (number <= 0 || number > 26 );
    return number;
}

void PrintLettersInPattern (int number)
{
    for (int j = number; j>= 1; j--) // loop to minusing one time when finish
    {
        char C = j + 64;
        for (int i = 1; i<=j; i++) // loop to print in times (1 to number) 
        {
            cout << C ;
        }
     cout << endl;
    }
}

int main ()
{
    PrintLettersInPattern(ReadPositiveNumber("Enter a Number Between 1 and 26?"));
}
