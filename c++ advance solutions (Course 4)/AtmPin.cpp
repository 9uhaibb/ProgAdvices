#include<iostream>
using namespace std;

int ReadPostiveNumber (string massege, int &number)
{
        cout << massege << endl;
        cin >> number;
    return number;
}

string ChekPin (int number)
{
    if (number == 1234)
    {
        system("color 2F"); // screen color GREEN
        return "Your Balance is 7500.\n";
    }
    else 
        system("color 4F"); // screen color RED
        return "Wrong PIN.";
}

void PrintResult (string result)
{   
    cout << result << endl;
}

int main ()
{
    int number;
    do 
    {
    int Pin = ReadPostiveNumber("Enter PIN ?",number);
    PrintResult(ChekPin(Pin));
    } while (number != 1234);
}