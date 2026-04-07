#include<iostream>
#include<cmath>
using namespace std;

void ReadAndCheckNumbers (float &length, float &diagnle)
{
    do
    {
    cout << "\nEnter Rectangle length: "; cin >> length;
    cout << "Enter Rectangle Diagnle: "; cin >> diagnle;
    if (diagnle < length)
        cout << "Length Should be less or equal to Diagnle, try again:\n";
    }while (diagnle < length);
    
}

float CalculateRectangle (float length, float diagnle)
{
    float result = length*(sqrt(pow(diagnle,2) - pow(length,2)));   
    return result;
}

void PrintResult (float result)
{
    cout << "Area is: " << result << endl;
}

int main ()
{
float length,diagnle;
ReadAndCheckNumbers(length,diagnle);
PrintResult(CalculateRectangle(length,diagnle));
}
// area = (pi * pow(d,2)) /4   