#include<iostream>
#include<cmath>

using namespace std;

float ReadNumber ()
{
    int number;
    cout << "Enter a number?\n";
    cin >> number ;
    return number;
}

float Myabs (float Number)
{
    if (Number >= 0)
    {
        return Number;
    }
    else if (Number < 0)
    {
        return Number * -1; 
    }
}

int main ()
{
    float Number = ReadNumber();

    cout << "\nMy ABS Result : " << Myabs(Number);
    cout << "\nC++ ABS Result : " << abs(Number);
}