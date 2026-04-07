#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

enPrimeNotPrime CheckPrime(int number)
{
    int M = round(number / 2);
    for (int counter = 2; counter <= M; counter++)
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

void PrintArray(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void CopyOnlyPrimeNumbers(int arrSource /*المصدر*/[100], int arrCopy[100], int arrayLength, int &array2Length)
{
    int counter = 0; // counter for Prime numbers limit, i for source array numbers limit
    for (int i = 0; i < arrayLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            arrCopy[counter] = arrSource[i];
            counter++;
        }
    }
    array2Length = counter;
}

int main()
{
    int arr[100], arrayLength = 0;
    srand((unsigned)time(NULL));
    FillArrayWithRandomNumbers(arr, arrayLength);

    int arr2[100], array2Length = 0;
    CopyOnlyPrimeNumbers(arr, arr2, arrayLength, array2Length);

    cout << "\nArray 1 Elements:\n ";
    PrintArray(arr, arrayLength);

    cout << "\nPrime Numbers In Array 2 :\n ";
    PrintArray(arr2, array2Length);
}