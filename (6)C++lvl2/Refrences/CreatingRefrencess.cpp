#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &x = a; // now x and a are having the same address

    // print the address
    cout << &a << endl;
    cout << &x << endl;

    // print the values
    cout << a << endl;
    cout << x << endl;

    x = 20;
    cout << a << endl;
    cout << x << endl;

    a = 30;
    cout << a << endl;
    cout << x << endl;
    return 0;
}