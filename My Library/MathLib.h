#ifndef MYLIBRERY_A_
#define MYLIBRERY_A_

#include <iostream>
#include <cmath>

using namespace std;
namespace MathLib

{
    float ReadNumber()
    {
        float Number;
        cout << "Enter a number?\n";
        cin >> Number;
        return Number;
    }
    enum enPrimeNotPrime
    {
        Prime = 1,
        NotPrime = 2
    };
    enPrimeNotPrime CheckPrime(int Number)
    {
        int M = round(Number / 2);
        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
                return NotPrime;
        }
        return Prime;
    }
    bool isPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }
        return Number == Sum;
    }

    int SumOfDigits(int Number)
    {
        int Sum = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Sum = Sum + Remainder;
        }
        return Sum;
    }

    int ReverseNumber(int Number) // 1234 => 4321
    {
        int Remainder = 0, Number2 = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }
        return Number2;
    }

    int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int FreqCount = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
        return FreqCount;
    }

    bool IsPalindromeNumber(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }
    void SwapNumbers(int &A, int &B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
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
            cin >> AddMore;
        } while (AddMore);
    }

}

#endif