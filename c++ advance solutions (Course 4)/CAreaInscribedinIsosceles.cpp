#include<iostream>
#include <cmath>

using namespace std;

void ReadTriangleData (float &a, float &b)
{
    cout << "\nEnter Triangle leg length: "; cin >> a;
    cout << "Enter Length of the base of the triangle: "; cin>> b;
}

float CalculateCAreaIncripedInIsosceles (float a, float b)
{
    const float PI =3.14159265;
    float area = PI * ( ( pow(b,2) ) / 4 ) * ((2 * a - b )/(2 * a + b ));
    return area;
}

void PrintResult (float result)
{
    cout << "\nCircle Area Inscribed in Isosceles is: " << result ;
}

int main ()
{
    float a, b;
    ReadTriangleData(a,b);
    PrintResult(CalculateCAreaIncripedInIsosceles(a,b));
}

