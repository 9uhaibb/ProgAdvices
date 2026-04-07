#include<iostream>
#include<cmath>

using namespace std;
// round of 10.7 => 11,
// round of 10.4 => 10,
// round of 10.5 => 11.
float ReadNumber ()
{
    float number;
    cout << "Enter a number?\n";
    cin >> number ;
    return number;
}

float GetFractionsPart (float Number)
{
    return Number - int(Number) ;
}

int MyRound (float Number) //  (int => float) غيرت int إلى float هنا
{
    int intPart;
    intPart = int(Number);

    float FractionsPart = GetFractionsPart(Number);
    if (abs(FractionsPart) >= 0.5) // التعديل هنا في اقواس ال abs 
    {
        if (Number > 0)
            return ++intPart;
        else 
            return --intPart;
    }
    else
    {
        return intPart;
    }

}

int main ()
{

    float Number = ReadNumber();

    cout << "\nMy Round Result : " << MyRound(Number);
    cout << "\nC++ Round Result : " << round(Number);
}
