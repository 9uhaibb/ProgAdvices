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

void Swap(int &A, int &B)
{
    int temp;
    temp = A;
    A = B;
    B = temp;
}

void PrintResult (int Result)
{
    cout << Result << endl;
}

 int main ()
 {
    int A = ReadPositiveNumber ("Enter Number 1: ");
    int B = ReadPositiveNumber ("Enter Number 2: ");

    Swap(A,B);

    cout << A << endl << B;

 }