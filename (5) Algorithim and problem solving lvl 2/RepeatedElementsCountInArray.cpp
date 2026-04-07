#include <iostream>
using namespace std;

int ReadPositiveNumber(string massege)
{
    int number;
    do
    {
        cout << massege << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

void ReadArray(int arr[100],int &arrayLength)
{
    cout << "\nEnter Number Of Elements?\n";
    cin >> arrayLength;
    cout << "\nEnter Array Elements: "; cout << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "Element [" << i + 1 << "]: "; 
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray (int arr[100], int arrayLength)
{
    for (int i = 0; i<arrayLength ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimesRepeated (int Number, int arr[100], int arrayLength)
{
    int counter =0 ;
    for (int i = 0 ; i <= arrayLength; i++)
    {
        if (Number == arr[i])
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    int arr[100],arrayLength, NumberToCheck;
    
    ReadArray(arr,arrayLength);

    NumberToCheck = ReadPositiveNumber("Enter The Number You Want To Check: ");

    cout << "\nOriginal Array:";
    PrintArray(arr,arrayLength);

    cout << "Number " << NumberToCheck << " is Repeated "
         << TimesRepeated (NumberToCheck, arr, arrayLength) << "Time(s).\n";
}