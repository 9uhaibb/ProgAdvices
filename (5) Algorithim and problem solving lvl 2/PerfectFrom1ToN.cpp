#include<iostream>
#include<cmath>
using namespace std;

int ReadPositiveNumber (string massege)
{
    int number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    }while (number <= 0);
    return number;
}

bool CheckPerfect (int number)
{
    int sum = 0;
    for (int i =1; i< number ; i++)
    {
        if (number % i == 0) // اذ ايقبل القسمة
        {
            sum += i;
        }
    }
    return number == sum; // اذا الرقم يساوي المجموع , رجلعي ياه
}

void PrintPerfectNumberFrom1ToNType (int number)
{
    cout << "Perfect Numbers From " << 1 << " To " << number;
    cout << " are: \n";
    for (int i = 1; i <= number ; i++)
    if (CheckPerfect(i) == true)
        cout << i << endl;
}

int main ()
{
    PrintPerfectNumberFrom1ToNType(ReadPositiveNumber("Enter Positive Number?"));
}