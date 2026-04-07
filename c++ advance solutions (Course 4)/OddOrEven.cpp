#include <iostream>
using namespace std;

enum enNumberType {odd = 1, even = 2 };

void ReadNumber(int &num)
{
    cout << "Enter a number : "; cin >> num;
}

enNumberType CheckNumberType (int num)
{
    int result = num % 2 ;
    if (result == 0)
        return enNumberType::even;
    else
        return enNumberType::odd;
}

void PrintNumberType(enNumberType NumberType)
{
    if (NumberType == enNumberType::even)
        cout << "Number is even.\n";
    else 
        cout << "Number is odd.\n";
}

int main () {
    int num;
    ReadNumber(num);
    PrintNumberType(CheckNumberType(num));
}