#include<iostream>
using namespace std;

int ReadN ()
{
    int n;
    cout << "Enter N: "; cin >> n; return n;
}

void PrintFrom1ToN_UsingFor (int n)
{
    for (int i = 1; i <= n ; i++)
    {
        cout << i << endl;
    }
}

void PrintFrom1ToN_UsingWhile (int n)
{
    int i = 1;
    while (n >= i)
    {
        cout << i << endl;
        i++;
    }
}

void PrintFrom1ToN_DoWhile (int n)
{
    int i = 1;
    do
    {
        cout << i << endl;
        i++;
    } while (n >= i);
    
}

int main ()
{
    int t = ReadN();
    PrintFrom1ToN_UsingFor(t);
    //PrintFrom1ToN_DoWhile(t);
    //PrintFrom1ToN_UsingWhile(t);
}