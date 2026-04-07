#include<iostream>
using namespace std;
int main ()
{
    // Sum odd numberes from 1 to n
    
    int number;
    int sum = 0;
    cout << "enter a number : ";
    cin >> number;

    for (int i = 1 ; i <= number ;)
    {
        sum += i;
        i += 2;
    }
    cout << "Sum is : " << sum << endl;

    
}