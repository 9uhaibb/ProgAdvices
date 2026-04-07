#include<iostream>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Enter a number? ";
    cin >> number;
    return number;

}

void AddElementInArray (int Number, int array [100], int &arrayLength)
{
    arrayLength++;
    array[arrayLength - 1] = Number;
}

void InputNumbersInArrayByUser (int array [100], int &arrayLength) 
{
    int AddMore = 1;
    do 
    {
        AddElementInArray (ReadNumber (), array, arrayLength);
        cout << "Do You Want to Add More Numbers?\n[0]: No.\n[1]:Yes.\n";
        cin >> AddMore;
    } while (AddMore == 1);
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
    int array[100], arrayLength = 0;
    InputNumbersInArrayByUser (array, arrayLength);

    cout << "array Length: " << arrayLength << endl;
    cout << "array Elements: "; PrintArray(array, arrayLength);
}