#include <iostream>
using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

void Read3Numbers (float  numbers[2]) 
{
    cout << "Enter Number 1 : ";
    cin >> numbers[0];

    cout << "Enter Number 2 : ";
    cin >> numbers[1];

    cout << "Enter Number 3 : ";
    cin >> numbers[2];
}

float Sum3Numbers (float numbers[2]) 
{
    float result = numbers[0] + numbers[1] + numbers [2];
    return result;
}

float CalculateAvg (float numbers [2]) 
{
    float avg = Sum3Numbers(numbers) / 3;
    return avg;
}

enPassFail CheckAvg (float avg) 
{
    if (avg >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}
void PrintResult (float avg) //مش شرط يكون ْ نفس اللي بالتشيكavg
{
    cout << "Average is : " << avg << endl;
    if (CheckAvg(avg) == enPassFail::Pass)
        cout << "You Passed.";
    else
        cout << "\n You Failed.";
}

int main () 
{
    float numbers[2];
    Read3Numbers(numbers);
    PrintResult(CalculateAvg(numbers));
}