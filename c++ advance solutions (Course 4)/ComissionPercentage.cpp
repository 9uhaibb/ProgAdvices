#include <iostream>
using namespace std;

int ReadTotalSeales ()
{
    int total_sales ;
    cout << "Enter Total Sales : ";
    cin >> total_sales; return total_sales;
}

float GetCommisionPercentage (float total_sales) 
{
    if (total_sales >= 1000000)
    {
        return 0.01;
    }
    else if (total_sales >= 500000)
    {
        return 0.02;
    }
    else if (total_sales >= 100000)
    {
        return 0.03;
    }
    else if (total_sales >= 50000)
    {
        return 0.05;
    }
    else
    {
        return 0.00;
    }
}

float CalculateTotalCommision (float total_sales) 
{
    return GetCommisionPercentage(total_sales) * total_sales ;
}

int main ()
{
    float total_sales = ReadTotalSeales ();
    cout << endl << "Commision Percentage: " << GetCommisionPercentage (total_sales) ;
    cout << endl << "Total commision: " << CalculateTotalCommision (total_sales) ;
}