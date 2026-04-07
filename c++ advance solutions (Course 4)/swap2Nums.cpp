#include<iostream>
using namespace std;


void ReadNumbers(float &x,float &y,float &z)
{
    cout << "Enter Number 1: " ;cin >> x;
    cout << "Enter Number 2: " ;cin >> y;
}

float SwapX(float x, float y, float z)
{
    z = x;
    x = y;
    y = z;
    return x ;
}

float SwapY(float x, float y, float z)
{
    z = x;
    x = y;
    y = z;
    return y ;
}

void PrintBeforeSwap (float x, float y)
{
    cout << "\nBefore Swap : \n";
    cout << "Number 1 is: " << x << endl;
    cout << "Number 2 is: " << y << endl;
}

void PrintResult (float resultX, float resultY)
{
    cout << "\nAfter Swap : \n";
    cout << "Number 1 is: " << resultX << endl;
    cout << "Number 2 is: " << resultY << endl;
}

int main ()
{
    float x,y,z;
    ReadNumbers (x,y,z);
    PrintBeforeSwap(x,y);
    PrintResult(SwapX(x,y,z),SwapY(x,y,z));
}