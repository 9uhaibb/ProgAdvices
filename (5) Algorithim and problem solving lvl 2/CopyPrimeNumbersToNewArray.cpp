#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

enPrimeNotPrime CheckPrime (int number)
{
    int M = round(number / 2);
    for (int counter = 2; counter <= M;counter++)
    {
        if (number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
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

void AddElementInArray (int Number, int array [100], int &arrayLength)
{
    arrayLength++;
    array[arrayLength - 1] = Number;
}

void PrintArray(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void CopyPrimeNumbersFromArray (int arrSource [100], int arrCopy[100], int arrayLength, int &arrayLength2) 
{
    for (int i = 1; i < arrayLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            AddElementInArray(arrSource[i],arrCopy,arrayLength2);
        }
    }
}

int main () 
{
    int array[100], PrimeArray[100], arrayLength = 0, PrimeArrayLength = 0;

    srand((unsigned)time(NULL));
    FillArrayWithRandomNumbers(array, arrayLength);

    CopyPrimeNumbersFromArray (array,PrimeArray,arrayLength,PrimeArrayLength);

    cout << "Array 1 Elements: \n";
    PrintArray(array,arrayLength);
    cout << "Prime Elements: \n";
    PrintArray(PrimeArray,PrimeArrayLength);
}