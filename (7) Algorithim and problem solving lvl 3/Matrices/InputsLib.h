#ifndef MYLIBRERY_H_
#define MYLIBRERY_H_

#include <iostream>


using namespace std;
namespace InputsLib
{
    int ReadNumber()
    {
        int Number;
        cout << "Enter a number ?\n";
        cin >> Number;
        return Number;
    }

    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    string ReadText()
    {
        string Text;
        cout << "Please Enter Text?\n";
        getline(cin, Text);
        return Text;
    }

    void AddArrayElement(int Number, int arr[100], int &arrLength)
    {
        // its a new element so we need to add the length by 1
        arrLength++;
        arr[arrLength - 1] = Number;
    }


    void InputUserNumbersInArray(int arr[100], int &arrLength)
    {
        bool AddMore = true;
        do
        {
            AddArrayElement(ReadNumber(), arr, arrLength);
            cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
                cin >>
                AddMore;
        } while (AddMore);
    }

}
#endif