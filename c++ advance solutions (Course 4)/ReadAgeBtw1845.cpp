#include<iostream>
using namespace std;

int ReadAge ()
{
    int age;
    cout << "Enter Age Between 18 And 45:\n";
    cin >> age ;
    return age;
}

bool ValidateNumberInRange (int number ,int from, int to)
{
    return (number >= from <= to);
}

int ReadUntillAgeBetween (int from, int to)
{
    int age = 0;
    do
    {
        age = ReadAge();
    } while (!ValidateNumberInRange(age , 18 , 45));
                                 // num ,from, to)     
    return age;     
}

void PrintResult (int age)
{
    cout << "Your age is: " << age << endl;
}

int main ()
{
    PrintResult(ReadUntillAgeBetween(18,45));
}