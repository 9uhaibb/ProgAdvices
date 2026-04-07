#include<iostream>
#include<cmath>

using namespace std;
// floor minusung the number (whatver the fraction is)

//floor of  10.7 ||  10.5 ||  10.4 =>  10
//floor of -10.7 || -10.5 || -10.4 => -11

float ReadNumber ()
{
    float number;
    cout << "Enter a number?\n";
    cin >> number ;
    return number;
}

int MyFloor (float Number) 
{
    int intPart;
    intPart = int(Number);

    if (Number > 0)
    {
        return intPart;
    }
    else 
    {
        return --intPart;
    }
}

int main ()
{

    float Number = ReadNumber();

    cout << "\nMy Floor Result : " << MyFloor(Number);
    cout << "\nC++ Floor Result : " << floor(Number);
}
