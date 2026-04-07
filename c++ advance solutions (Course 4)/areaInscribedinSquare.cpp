#include<iostream>
#include <cmath>
using namespace std;

float ReadSquareLength ()
{
    float A;
    cout << "Enter Square Length: "; cin >> A;
    return A;
}
float CalculatAreaInscribedInSquare (float A)
{
    const float PI = 3.14159265;
    const float area = (PI * pow(A,2))/4;
    return area;
}
void PrintResult (const float area)
{
    cout << "\nCircle Area is: " << area << endl;
}
int main ()
{
    
    PrintResult(CalculatAreaInscribedInSquare(ReadSquareLength()));
}