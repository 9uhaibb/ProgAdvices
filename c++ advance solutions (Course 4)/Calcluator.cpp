#include<iostream>
using namespace std;

enum enOperator {Add = '+', Subtract = '-', Divide = '/', Multiply = '*'};

int ReadNumber(string massege)
{
    float number = 0 ;
    cout << massege;
    cin >> number;
    return number;
}

enOperator ReadOperator ()
{
    char Operator;
    cout << "Please Enter Operator: ";
    cin >> Operator;
    return (enOperator)Operator;
}

float Calculate (float number1, float number2, enOperator Operator)
{
    switch (Operator)
    {
        case enOperator::Add:
            return number1 + number2;
        case enOperator::Subtract:
            return number1 - number2;
        case enOperator::Multiply:
            return number1 * number2;
        case enOperator::Divide:
            return number1 / number2;
        default:
            cout << "Invalid Input.";
            return number1 + number2;
    }
}

int main ()
{
    float number1 = ReadNumber ("Please Enter First Number: ");
    float number2 = ReadNumber ("Please Enter Second Number: ");

    enOperator OpType = ReadOperator ();

    cout << endl << "Result = " << Calculate (number1, number2, OpType);
}