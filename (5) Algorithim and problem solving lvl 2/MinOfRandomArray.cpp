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

int MinNumberInArray (int arr[100], int arrayLength)
{
    int Min =0;
    Min = arr[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if (arr[i] < Min) 
        {
            Min = arr[i];
        }
    }
    return Min;
}

int main()
{
    int arr[100], arrayLength, number1, number2;
    srand((unsigned)time(NULL));
    FillArrayWithRandomNumbers(arr, arrayLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrayLength);

    cout << "\nMin Number: " << MinNumberInArray (arr, arrayLength);


}