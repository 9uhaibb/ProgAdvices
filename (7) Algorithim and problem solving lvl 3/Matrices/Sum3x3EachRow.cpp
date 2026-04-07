// print random 3 * 3 array, then find the sum of each row

#include <iostream>
#include <iomanip>
#include<ctime>

using namespace std;

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill2DArrayWithRandomNumbers(int Array[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            Array[i][j] = RandomNumber(1, 100);
        }
    }
}

void Print2DArray(int Array[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << setw(3) << Array[i][j] << "  "; 
        }
        cout << endl;
    }
}

int RowSum (int Array[3][3], short RowNumber, short Col)
{
    int Sum = 0;
    for (int i = 0; i < Col; i++)
    {
        Sum += Array[RowNumber][i];
    }
    return Sum;
}

void PrintSumOfEachRow (int Array[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        cout << "Row " << i + 1<< " Sum : " << RowSum(Array, i, Col) << endl;
    }
}

int main()
{
    //Seeds the random number generator in c++
    srand((unsigned)time(NULL));

    int Array[3][3];

    cout << "Matrix Elements : \n";
    Fill2DArrayWithRandomNumbers(Array, 3, 3);
    Print2DArray(Array ,3 ,3);
    cout << endl;

    cout << "Each Row Sum (Printed Normally) : \n";
    PrintSumOfEachRow(Array, 3, 3);
}

// My Mistakes:
/*
    didin't create the function RowSum ();
*/

