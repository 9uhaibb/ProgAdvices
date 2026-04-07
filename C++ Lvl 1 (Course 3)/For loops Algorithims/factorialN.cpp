#include <iostream>
using namespace std;

int main ()
{
    // ex: 4! = 4*3*2*1 = 24
    int number;
    int factorial = 1;
    cout << "Enter a number : ";
    cin >> number;
    for (int i = number ; i>= 1; i--)
    {
       factorial *= i;
       // u can put i-- here AFTER FACTORIAL 
    }
    cout << number << "! = " << factorial << endl;
}