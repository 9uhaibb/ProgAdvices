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

void CopyArray ( int arrSource/*المصدر*/[100],int arrCopy[100],int arrayLength)
{
    for (int i = 0; i < arrayLength ; i++)
    {
        arrCopy[i] = arrSource[i];
    }
}

int main()
{
    int arr[100], arrayLength;
    srand((unsigned)time(NULL));
    FillArrayWithRandomNumbers(arr, arrayLength);

    cout << "\nArray 1 Elements:\n ";
    PrintArray(arr, arrayLength);

    int arr2[100];
    CopyArray(arr,arr2,arrayLength);

    cout << "\nArray 2 Copied :\n ";
    PrintArray(arr2, arrayLength);
}