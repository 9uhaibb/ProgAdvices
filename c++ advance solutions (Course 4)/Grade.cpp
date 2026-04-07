#include<iostream>
using namespace std;

float ReadNumberInRange(int from, int to)
{
    float number;
    do 
    {
    cout << "Enter Your Grade (between 0 and 100) : ";
    cin >> number;
    } while (from >= number >= to);
    return number;
}

char CheckMark (float number)
{
    if (90 <= number)
    {
        return 'A';
    }
    else if (80 <= number)
    {
        return 'B';
    }
    else if (70 <= number)
    {
        return 'C';
    }
    else if (60 <= number)
    {
        return 'D';
    }
    else 
    {
        return 'F';
    }
}


int main ()
{
    
    cout << "Your Result is : " << CheckMark(ReadNumberInRange(0,100));
}