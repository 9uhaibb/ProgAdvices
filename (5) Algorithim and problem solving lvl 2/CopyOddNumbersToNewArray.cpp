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
        arr[i] = RandomNumber(1, 100);
    }
}

void AddElementInArray (int Number, int array [100], int &arrayLength)
{
    arrayLength++;
    array[arrayLength - 1] = Number;
}

void CopyOddNumbersUsingAddElementInArray (int arrSource[100],int arrCopy[100],int arrayLength, int &arrayLength2)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (arrSource[i] % 2 != 0)
        {
            AddElementInArray(arrSource[i],arrCopy,arrayLength2);
        }
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

int main ()
{
    int array[100],  OddArray[100], arrayLength = 0, arrayLength2 = 0;
    srand((unsigned)time(NULL));

    FillArrayWithRandomNumbers(array, arrayLength);
    CopyOddNumbersUsingAddElementInArray ( array, OddArray, arrayLength, arrayLength2);

    cout << "Array 1 Elements: \n";
    PrintArray(array,arrayLength);
    cout << "\nArray 2 Odd Numbers: \n";
    PrintArray(OddArray,arrayLength2);
}