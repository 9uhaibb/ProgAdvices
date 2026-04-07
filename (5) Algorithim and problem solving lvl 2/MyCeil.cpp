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

int MyCeil (float Number) 
{
    int intPart;
    intPart = int(Number);

    if (Number > 0)
    {
        return ++intPart;
    }
    else 
    {
        return intPart;
    }
}

int main ()
{

    float Number = ReadNumber();

    cout << "\nMy Ceil Result : " << MyCeil(Number);
    cout << "\nC++ Ceil Result : " << ceil(Number);
}
