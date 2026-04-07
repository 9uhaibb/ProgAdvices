#include<iostream>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Enter an integer number : "; 
    cin >> number ;
    return number;
}

int ReadPower ()
{
    int number;
    cout << "Enter an integer power : "; 
    cin >> number ;
    return number;
}

int CalculateNumToPower (int number , int power)
{
    if (power == 0) 
    {
        return 1;
    }
    
    int P = 1;
        for (int i =1 ; i<=power ; i++)
        {
           P *= number;
        }
    return P;
    
}

int main ()
{
    cout << CalculateNumToPower(ReadPower() , ReadNumber())/*
    if u call functions inside a function, execution starts right to left*/;
}