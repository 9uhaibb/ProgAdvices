#include <iostream>
#include <string>
using namespace std;


int ReadNumber()
{
    int num;
    cout << "\nEnter a number : "; cin >> num;
    return num;
}

float CalculateHAlfNum (int num)
{
    return (float)num /2 ; // float علشان ما تروح الكسور
}

void PrintResult (int num)
{
    string result = "Half of " + to_string(num) + " is " + to_string(CalculateHAlfNum(num));
    cout << " " << result ;
}


int main () 
{
    do 
    {
   PrintResult(ReadNumber()); 
    } while (1>0);
}