#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int ReadNumber ()
{
    int number;
    do 
    {
    cout << "Enter a Number to Search?" << endl;
    cin >> number;
    }while (number <= 0 );
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

void PrintArray(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

short FindNumberPositionINArray (int number,int array[100], int arrayLength)
{
    for (int i = 0; i <= arrayLength; i++)
    {
        if (number == array[i])
        {
            return i;
        }
    }
    return -1; // if u reach here, this means the number is not found.
}

bool ISNumberInArray (int number,int array[100], int arrayLength)
{
    return FindNumberPositionINArray( number, array, arrayLength) != -1; 
}

int main ()
{
    int array[100], arrayLength; 

    srand((unsigned)time(NULL));


    FillArrayWithRandomNumbers(array,arrayLength);
    PrintArray(array,arrayLength);

    int number = ReadNumber();
    cout << "The number you are looking for is: " << number;

        if (ISNumberInArray ( number, array,  arrayLength) == true)
    {
        cout << "\nYes, The Number is Found :) ";
    }
    else 
    {
        cout << "\nNo, The Number is Not Found :(";
    }



}