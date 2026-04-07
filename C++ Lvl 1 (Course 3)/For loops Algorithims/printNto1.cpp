#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter a number \n";
    cin >> number;//10

    for (int i = (number - 1); i >= 1; i--)// i = 9
    {
        cout << i << endl; // 10 9 
    }
}