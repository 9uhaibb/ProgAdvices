#include <iostream>
using namespace std;

int main ()
{
    int number, m;

    cout << "Enter Number : ";
    cin >> number;

    cout << "Enter M : ";
    cin >> m;

    for (int i = 1; i <=m; i++)
    {
        number *= m;
    }
    cout << number;
}