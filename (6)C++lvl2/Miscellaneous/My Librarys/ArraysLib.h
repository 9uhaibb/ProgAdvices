#ifndef MYLIBRERY_B_
#define MYLIBRERY_B_

#include <iostream>
#include <cmath>

using namespace std;

namespace ArraysLib
{
    int RandomNumber(int From, int To)
    {
        // Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    void ReadArray(int arr[100], int &arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;
        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
        cout << endl;
    }
    void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int count = 0;
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (Number == arr[i])
            {
                count++;
            }
        }
        return count;
    }
    // Fill Array With Random Numbers from 1 to 100
    // Input:
    // 10
    // Output:
    // Array Elements: 56 55 83 71 32 52 17 28 71 52
    void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }
    void FillArrayWithRandomNumbers(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }
    // Max of Random Array
    // Input:
    // 10
    // Output:
    // Array Elements: 65 91 54 42 75 32 53 57 57 30
    // Max Elements: 91
    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }
    // Min of Random Array
    // Input:
    // 10
    // Output:
    // Array Elements: 30 99 72 47 95 67 29 13 80 64
    // Min Elements: 13
    int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = 0;
        Min = arr[0];
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }
    // Sum of Random Array
    // Input:
    // 10
    // Output:
    // Array Elements: 10 6 22 40 12 75 23 32 25 75
    // Sum of all number is: 320
    int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }
    float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }
    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
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


    void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100],
                              int arrLength, int &arr2Lenght)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {

            if (CheckPrime(arrSource[i]) == Prime)
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;
            }
        }
        arr2Lenght = --Counter;
    }
    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }
    void FillArrayWith1toN(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    
    }

        void SwapNumbers(int &A, int &B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }


    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            SwapNumbers(arr[RandomNumber(1, arrLength) - 1],
                        arr[RandomNumber(1, arrLength) - 1]);
        }
    }
    // Copy Array In Reverse Order
    // Input:
    // 10
    // Output:
    // Array 1 elements:
    // 64 8 62 19 2 21 15 74 96 85
    // Array 2 elements after copying array 1 in reversed order:
    // 85 96 74 15 21 2 19 62 8 64
    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }
    // Return number index in array
    // Input:
    // Enter number of elements:
    // 10
    // Output:
    // Array 1 elements:
    // 90 89 62 62 91 47 60 67 60 67
    // Please enter a number to search for?
    // 62
    // Number you are looking for is: 62
    // The number found at position: 2
    // The number found its order: 3
    short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        /*This function will search for a number in array and return its
        index,
        or return -1 if it does not exists*/
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i; // and return the index
        }
        // if you reached here, this means the number is not found
        return -1;
    }
    void AddArrayElement(int Number, int arr[100], int &arrLength)
    {
        // its a new element so we need to add the length by 1
        arrLength++;
        arr[arrLength - 1] = Number;
    }
    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
            AddArrayElement(arrSource[i], arrDestination,
                            arrDestinationLength);
    }
    // Solution #38/2
    // Copy Odd Numbers to a new Array
    // Input:
    // 10
    // Output:
    // Array 1 elements:
    // 59 14 84 36 6 51 48 91 96 67
    // Array 2 Odd numbers:
    // 59 51 91 67
    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (arrSource[i] % 2 != 0)
            {
                AddArrayElement(arrSource[i], arrDestination,
                                arrDestinationLength);
            }
    }
    // Solution #39/2
    // Copy Prime Numbers to a new Array
    // Input:
    // 10
    // Output:
    // Array 1 elements:
    // 61 100 32 75 81 95 50 98 13 70
    // Array 2 Prime numbers:
    // 61 13
    void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (CheckPrime(arrSource[i]) == Prime)
            {
                AddArrayElement(arrSource[i], arrDestination,
                                arrDestinationLength);
            }
    }
    // Solution #40/2
    // Copy Distinct Numbers to Array
    // Output:
    // Array 1 elements:
    // 10 10 10 50 50 70 70 70 70 90
    // Array 2 distinct elements:
    // 10 50 70 90
    void FillArray(int arr[100], int &arrLength)
    {
        // Hard coded array elements
        arrLength = 10;
        arr[0] = 10;
        arr[1] = 10;
        arr[2] = 10;
        arr[3] = 50;
        arr[4] = 50;
        arr[5] = 70;
        arr[6] = 70;
        arr[7] = 70;
        arr[8] = 70;
        arr[9] = 90;
    }

    int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int count = 0;
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (Number == arr[i])
            {
                count++;
            }
        }
        return count;
    }
    bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }
    bool IsPalindromeArray(int arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            if (arr[i] != arr[Length - i - 1])
            {
                return false;
            }
        };
        return true;
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!IsNumberInArray(arrSource[i], arrDestination,
                                 DestinationLength))
            {
                AddArrayElement(arrSource[i], arrDestination,
                                DestinationLength);
            }
        };
    }
    int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;
            }
        }
        return Counter;
    }
    // Count Even Numbers In Array
    // Input:
    // 10
    // Output:
    // Array Elements: 14 92 70 15 58 76 84 62 10 43
    // Even Numbers count is: 8
    int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;
    }
    // Count Positive Numbers In Array
    // Input:
    // 10
    // Output:
    // Array Elements: 17 -9 -9 -90 -72 -100 -4 60 -84 -15
    // Positive Numbers count is: 2
    int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;
            }
        }
        return Counter;
    }
    // Count Negative Numbers In Array
    // Input:
    // 10
    // Output:
    // Array Elements: -58 -16 -21 -4 -91 82 98 66 -8 -33
    // Negative Numbers count is: 7
    int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

}

#endif