#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int From, int To)
{
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrayLength)
{
    cout << "Enter Number Of Elements?\n";
    cin >> arrayLength;
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = RandomNumber(-100, 100);
    }
}

void PrintArray(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int CountNegativeNumbersInArray (int arrSource[100],int arrayLength)
{
    int NegativeCounter = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (arrSource[i] < 0)
        {
            NegativeCounter++;
        }
    }
    return NegativeCounter;
}

int main ()
{
    int array[100], arrayLength = 0;

    srand((unsigned)time(NULL));

    FillArrayWithRandomNumbers(array, arrayLength);

    cout << "Array Elements: \n";
    PrintArray(array, arrayLength);
   

    cout << "Negative Numbers Count is: "
         << CountNegativeNumbersInArray(array, arrayLength);

}