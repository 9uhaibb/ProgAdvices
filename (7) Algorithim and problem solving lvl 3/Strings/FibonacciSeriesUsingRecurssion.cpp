// Fibonacci series of 10, using recurssion(Function call it self)

#include<iostream>

using namespace std;

void PrintFibonacciSeriesUsingRecurssion (short Number, int Prev1, int Prev2)
{
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;

        cout << FebNumber << "     ";

        PrintFibonacciSeriesUsingRecurssion(Number - 1, Prev1, Prev2);
    }
}

int main ()
{
    PrintFibonacciSeriesUsingRecurssion(10, 1, 0);
}