#include<iostream>
#include<string>
using namespace std;

void PrintAtoZ()
{
    for (char counter = 'A'; counter <= 'Z'; counter ++)
    {
        cout << counter << endl;
    }
}

void AnotherWay ()
{
    for (int i = 60 /* A in ASCI*/; i <= 90 /*A in ASCI*/; i++)
    {
        cout << char(i) << endl;
    }
}

int main ()
{
    cout << "Method 1 :\n";PrintAtoZ();
    cout << "Method 2 : \n"; AnotherWay();
}