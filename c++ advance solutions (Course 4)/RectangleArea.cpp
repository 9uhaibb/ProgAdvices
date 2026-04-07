#include <iostream>
using namespace std;

void ReadNumbers (float &a , float &b)
{
    cout << "Enter A: "; cin >> a;
    cout << "Enter B: "; cin >> b;
}

float CalculateRectangle (float a, float b)
{
    return a*b ;
}

void PrintResult(float area)
{
    cout << "Area is: " << area << endl;
}

int main ()
{
    float a, b;
    ReadNumbers(a,b);
    PrintResult(CalculateRectangle(a,b) /*area*/);
}