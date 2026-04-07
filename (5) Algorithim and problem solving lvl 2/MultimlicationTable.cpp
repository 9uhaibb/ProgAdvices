#include<iostream>
#include<cmath>
 using namespace std;

void PrintTableHeader ()
{
    cout <<"\n\n\t\t\t Multipliacation Table From 1 to 10\n\n";
    cout << "\t";
    for (int i = 1 ; i<= 10; i++ )
    {
        cout << i << "\t" ;
    }   
    cout << "\n_________________________________________________________________________________________\n"; 
}

string ColomSeperator (int i)
{
    if (i < 10)
        return "    |";
    else
        return "   |";
}

string ColomSeperator2 (int k)
{
    if (k < 100)
        return " |";
    else
        return "|";
}

void PrintMultiplicationTable ()
{
    PrintTableHeader();
    for (int i = 1; i <= 10 ; i++)
    {
        cout << " " << i << ColomSeperator(i)<< "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << ColomSeperator2(i) << endl;
    }
    cout << "_________________________________________________________________________________________\n"; 
}

 int main ()
 {
    PrintMultiplicationTable();
 }