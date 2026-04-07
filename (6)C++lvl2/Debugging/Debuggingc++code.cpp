#include<iostream>
#include "MathLib.h"
using namespace std;

int MySum (int a, int b)
{
    int s = a + b;
    return s;
}

int main ()
{
    int arr [100] = {100, 200, 300};
    int number = MathLib::ReadNumber ();
    cout << number << endl;
    int a, b, c;

    a = 9;
    b = 4;
    c = b + a;
    ++a;
    b++;
    --c;

    for (int i = 1; i <= 5; i++)
    {
        a++;
        b++;
        c++;
    }

    c = MySum (a, b);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}