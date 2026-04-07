#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

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

void FillArrayWithRandomNumbers(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void Sum2Arrays (int arr1[100], int arr2[100], int arrSum[100], int arrayLength)
{
    for (int i =0; i < arrayLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
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

int main()
{
    int arr1[100], arr2[100], arrSum[100];
    int arrayLength = ReadPositiveNumber("Enter Number Of Elements?");

    srand((unsigned)time(NULL));
    
    FillArrayWithRandomNumbers(arr1, arrayLength);
    FillArrayWithRandomNumbers(arr2, arrayLength);
    Sum2Arrays(arr1, arr2, arrSum, arrayLength);

    cout << "\nArray 1 Elements: \n";
    PrintArray(arr1, arrayLength);
    cout << "\nArray 2 Elements: \n";
    PrintArray(arr2, arrayLength);
    cout << "\nSum Of Arrays: \n";
    PrintArray(arrSum, arrayLength);
    

}