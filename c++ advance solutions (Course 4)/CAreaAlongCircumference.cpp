#include<iostream>
#include<cmath>

using namespace std;

float ReadLength ()
{
    float length;
    cout << "\nEnter Length: "; cin >> length; return length;
}
float CalculateCAreaAlongCircuumference(float length)
{
    const float Pi = 3.14159265;
    const float area = (pow(length,2))/(Pi * 4); return area;
}
void PrintResult (float result)
{
    cout << "\nCircle Area Along a Circuumference is: " << result;
}

int main ()
{
    PrintResult(CalculateCAreaAlongCircuumference(ReadLength()));
}