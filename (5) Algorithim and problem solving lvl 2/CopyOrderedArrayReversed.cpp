#include<iostream>
#include<cstdlib>
#include <ctime>
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
        arr[i] = RandomNumber(1, 100);
    }
}

void CopyArray ( int arrSource/*المصدر*/[100],int arrReversedCopy[100],int arrayLength)
{
    for (int i = 0; i < arrayLength ; i++)
    {
        arrReversedCopy[i] = arrSource[i];
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


void PrintReversedArray(int arr[100], int arrayLength)
{
    for (int i = arrayLength - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main ()
{
    int arr[100], arrayLength;
    srand((unsigned)time(NULL));

    FillArrayWithRandomNumbers(arr, arrayLength);

    cout << "\nArray 1 Elements:\n ";
    PrintArray(arr, arrayLength);

    int arrReversedCopy[100];
    CopyArray(arr,arrReversedCopy,arrayLength);
    cout << "\nArray 2 elements after copying array 1 reversed in order:\n";
    PrintReversedArray(arrReversedCopy,arrayLength);
}