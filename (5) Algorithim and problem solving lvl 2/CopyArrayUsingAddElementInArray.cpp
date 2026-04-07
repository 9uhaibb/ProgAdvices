#include <iostream>
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
        arr[i] = RandomNumber(1, 100);
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

void AddElementInArray (int Number, int array [100], int &arrayLength)
{
    arrayLength++;
    array[arrayLength - 1] = Number;
}

void CopyArrayUsingAddElementInArray (int arrSource[100],int arrCopy[100], int arrayLength, int &arrCopyLength)
{
    for (int i = 0; i < arrayLength; i++)
        AddElementInArray(arrSource[i], arrCopy, arrCopyLength);
}

int main()
{
    int arr[100], arrayLength, arrayLength2 = 0;
    srand((unsigned)time(NULL));
    FillArrayWithRandomNumbers(arr, arrayLength);

    cout << "\nArray 1 Elements:\n ";
    PrintArray(arr, arrayLength);

    int arr2[100];
    CopyArrayUsingAddElementInArray(arr,arr2,arrayLength,arrayLength2);

    cout << "\nArray 2 Copied :\n ";
    PrintArray(arr2, arrayLength);
}