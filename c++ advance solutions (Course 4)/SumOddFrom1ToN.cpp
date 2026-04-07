#include<iostream>
using namespace std;

enum enOddEven {Odd = 1, Even = 2};

int ReadNumber ()
{
    int number;
    cout << "Enter a number : "; cin >> number;
    return number;
}

enOddEven CheckOddEven (int number)
{
    if (number % 2 !=0)
        return enOddEven::Odd;
    else
        return enOddEven::Even;
}

int PrintSumOddFrom1ToN_UsingFor (int number)
{
    int sum = 0;
    cout << "Sum Odd Numbers Using For Loop:\n";

    for(int counter = 1; counter <= number; counter++)
    {
        if (CheckOddEven(counter) == enOddEven::Odd)
        {
            sum += counter ;
        }
    }
    return sum;      
}

int PrintSumOddFrom1ToN_UsingWhile (int number)
{
    int sum =0;
    int counter = 1;
    cout << "Sum Odd Numbers Using While Loop:\n";
    while(counter <= number)
    {
        if (CheckOddEven(counter) == enOddEven::Odd)
        {
            sum += counter;
        }
        counter += 1;    
    }
    return sum;
}

int PrintSumOddFrom1ToN_UsingDoWhile (int number)
{
    int sum = 0;
    int counter = 1;
    cout << "Sum Using Do While Loop :\n";
    do 
    {
        if (CheckOddEven(counter) == enOddEven::Odd)
        {
            sum += counter;
        }
        counter += 1;
    } while (counter <= number);
    return sum;
}

int main ()
{
int N = ReadNumber();
cout << PrintSumOddFrom1ToN_UsingFor(N) << endl;
cout << PrintSumOddFrom1ToN_UsingWhile(N) << endl;
cout << PrintSumOddFrom1ToN_UsingDoWhile(N) << endl;
}