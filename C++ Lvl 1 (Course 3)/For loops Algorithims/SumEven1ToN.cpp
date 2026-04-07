#include <iostream>
using namespace std;

int main ()
{
    int number;
    int sum =0;
    cout << "Enter a number : ";
    cin >> number;

    for (int i = 0 ; i <= number ;)
    {
        sum += i;
        i += 2;
    }
    cout << "Sum is : " << sum << endl;
}