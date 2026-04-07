// print fibonacci series of 10
// 1 1 2 3 5 8 13 21 34 55

/*
    F: 
    PrintFibonacciSeries
    V: int Prev1 = 1 ,Prev2 = 1
    int Sum2PrevNumbers = Prev1 + Prev2
    Prev2 = Prev1, 
    Prev1 = Sum2PrevNumbers

*/

#include<iostream>

using namespace std;


void PrintFibonacciSeries (int Number)
{
    int Answer = 0, Prev1 = 1, Prev2 = 0 ;
    cout << Prev1 << "  ";
    for (int i = 2; i <= Number; i++)
    {
        Answer = Prev1 + Prev2; // 1 + 0 = 1, 
        cout << Answer << "  " ; // 1,
        Prev2 = Prev1; // = 1,
        Prev1 = Answer; // = 1,
    }

}

int main ()
{
    PrintFibonacciSeries (10);

    system("pause>0");
}