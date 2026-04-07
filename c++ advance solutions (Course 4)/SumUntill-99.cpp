#include<iostream>
using namespace std;

float ReadNumber(string massege)
{
    int number = 0;
    cout << massege << endl;
    cin >> number;
    return number;
}

float SumNumbers ()
{
    float sum = 0, number = 0; int counter = 1;
    do 
    {
        number = ReadNumber ("Enter number " + to_string(counter));
        if (number == -99)
        {
            break;
        }
        sum += number;
        counter++;
    } while (number != -99);
    return sum;
    
}

int main ()
{
    cout << endl << "Result = " << SumNumbers() << endl;
}