#include<iostream>
using namespace std;

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

bool isPalindromeArray (int array[100], int arrayLength)
{
    // 10 20 30 30 20 10
    // 0  1  2  3  4  5
    // arrLength = 6 here.
    for (int i = 0; i < arrayLength; i++)
    {                        //arrLength = user input
        if (array[i] != array[arrayLength - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    int array[100], arrayLength;

    ReadArray(array, arrayLength);
    cout << "Array Elememts:\n";
    PrintArray(array, arrayLength);

    if (isPalindromeArray(array, arrayLength) == true)
    {
        cout << "Yes, it's a Palindrome Array.";
    }
    else 
    {
        cout << "No, it's Not a Palindrome Array.";
    }


}