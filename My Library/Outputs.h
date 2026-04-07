#ifndef MYLIBRERY_C_
#define MYLIBRERY_c_

#include <iostream>
#include "ArraysLib.h"
#include "MathLib.h"

using namespace std;
namespace OutPuts
{
    int RandomNumber(int From, int To)
    {
        // Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    void PrintStringArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n";
    }
    void PrintNumberPosition(int Number, int arr[100], int arrLength)
    {
        short NumberPosition =ArraysLib:: FindNumberPositionInArray(Number, arr,
                                                         arrLength);
        if (NumberPosition == -1)
            cout << "The number is not found :-(\n";
        else
        {
            cout << "The number found at position: ";
            cout << NumberPosition << endl;
            cout << "The number found its order: ";
            cout << NumberPosition + 1 << endl;
        }
    }
    void PrintFoundOrNotFound(int Number, int arr[100], int arrLength)
    {
        cout << "\nNumber you are looking for is: " << Number << endl;
        if ( !ArraysLib::IsNumberInArray(Number, arr, arrLength))
            cout << "No, The number is not found :-(\n";
        else
        {
            cout << "Yes, it is found :-)\n";
        }
    }
    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4
    };
    char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        }
    }
    string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }
    string GenerateKey()
    {
        string Key = "";
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
        return Key;
    }
    void GenerateKeys(short NumberOfKeys)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }
    void PrintPerfectNumbersFrom1ToN(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            if (MathLib::isPerfectNumber(i))
            {
                cout << i << endl;
            }
        }
    }

    void PrintDigitsInReversedOrder(int Number) // يطبع كل رقم من العدد بالعكس
    {
        int Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }
    void PrintAllDigitsFrequencey(int Number)
    {
        cout << endl;
        for (int i = 0; i < 10; i++)
        {
            short DigitFrequency = 0;
            DigitFrequency = MathLib::CountDigitFrequency(i, Number);
            if (DigitFrequency > 0)
            {
                cout << "Digit " << i << " Frequencey is "
                     << DigitFrequency << " Time(s).\n";
            }
        }
    }
    void PrintDigits(int Number)
    {
        int Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }
    // Inverted Number Pattern
    // Input: Input:
    // 3 5
    // Output: Output:
    // 333 55555
    // 22 4444
    // 1 333
    // 22
    // 1
    void PrintInvertedNumberPattern(int Number)
    {
        cout << "\n";
        for (int i = Number; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << "\n";
        }
    }
    // Number Pattern
    // Input: Input:
    // 3 5
    // Output: Output:
    // 1 1
    // 22 22
    // 333 333
    // 4444
    // 55555
    void PrintNumberPattern(int Number)
    {
        cout << "\n";
        for (int i = 1; i <= Number; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << "\n";
        }
    }
    void PrintWordsFromAAAtoZZZ()
    {
        cout << "\n";
        string word = "";
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    word = word + char(i);
                    word = word + char(j);
                    word = word + char(k);
                    cout << word << endl;
                    word = "";
                }
            }
            cout << "\n____________________________\n";
        }
    }

}

#endif