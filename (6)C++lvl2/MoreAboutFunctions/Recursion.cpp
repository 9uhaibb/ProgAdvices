#include<iostream>
using namespace std;

void PrintNumbers (int From, int To)
{
    if (From <= To)
    {
        cout << From << endl;
        PrintNumbers(From + 1, To);
    }
}

void PrintNumbers2 (int To, int From )
{
    if (From <= To)
    {
        cout << To << endl;
        PrintNumbers2(To - 1, From);
    }
}

float NPowerM (int Base, int Power)
{
    if (Base == 0)
    
        return 1;
    else
        return (Base * NPowerM(Base, Power - 1));
    
}

int main ()
{
    cout << " 1 to 5 " << endl;
    PrintNumbers(1,5);
    cout << endl;

    cout << "5 to 1"  << endl;
    PrintNumbers2(5,1);
    cout << endl;

    cout << "My Power : " << endl;
    cout << NPowerM(2,4) << endl;
}