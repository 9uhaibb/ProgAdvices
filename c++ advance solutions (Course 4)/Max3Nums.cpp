#include<iostream>
using namespace std;

void ReadNumbers(int &a, int &b, int &c)
{
    cout << "Enter Number 1 : " ; cin >> a;
    cout << "Enter Number 2 : " ; cin >> b;
    cout << "Enter Number 3 : " ; cin >> c;
}
int Max3Numbers (int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else if (c > a && c > b)
    {
        return c;
    }
    
}
void PrintResult (int result,int a,int b,int c)
{
    if (a!=b)
    cout << "Max Number is: " << result << endl;
    else if (a==b&&b==c) 
    cout << "Numbers are equal." << endl;
}
int main () 
{
    
    int a,b,c;
    ReadNumbers(a,b,c);
    PrintResult(Max3Numbers(a,b,c),a,b,c);
   
}