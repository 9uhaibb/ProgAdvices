#include<iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


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

void Swap(int &A, int &B)
{
    int temp;
    temp = A;
    A = B;
    B = temp;
}

int RandomNumber(int From, int To)
{
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

void FillArrayWith1ToN (int array[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = i + 1;
    }
}

void ShuffleArray(int array[100], int arrayLength) 
{
    for (int i = 0; i < arrayLength; i++)
    {
        Swap(array[RandomNumber(1,arrayLength) - 1], array [RandomNumber(1,arrayLength) - 1]);
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
    srand((unsigned)time(NULL));

    int array [100];
    int arrayLength = ReadPositiveNumber("Enter Number Of Elements?");

    FillArrayWith1ToN(array, arrayLength);

    cout << "\nArray Before Shuffle: \n"; 
    PrintArray(array, arrayLength);
   
    ShuffleArray(array, arrayLength);
    cout << "\nArray After Shuffle: \n";
    PrintArray(array, arrayLength);



}