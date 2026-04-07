#include<iostream>
#include<cmath>

using namespace std;
// Ceil adding the number (whatver the fraction is)
//ceil of  10.7 ||  10.5 ||  10.4 =>  11

//ceil of -10.7 || -10.5 || -10.4 => -10

float ReadNumber ()
{
    float number;
    cout << "Enter a number?\n";
    cin >> number ;
    return number;
}

float MySqrt (float Number) 
{
    return pow(Number,0.5);
}


int main ()
{

    float Number = ReadNumber();

    cout << "\nMy Sqrt Result : " << MySqrt(Number);
    cout << "\nC++ Sqrt Result : " << sqrt(Number);
}
