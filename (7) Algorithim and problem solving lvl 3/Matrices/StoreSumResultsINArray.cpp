// Sum each colomun in random matrix to another array

#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill3x3MatrixRandomly (int Matrix[3][3], short Row, short Col)
{
    for (int RowCount = 0; RowCount < Row; RowCount++)
    {
        for (int ColCount = 0; ColCount < Col; ColCount++)
        {
            Matrix[RowCount][ColCount] = RandomNumber(1,100);
        }
    }
}

void Print3x3Matrix(int Matrix[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << setw(3) << Matrix[i][j] << "  "; 
        }
        cout << endl;
    }
}

int ColSum (int Array[3][3], short Row, short Col)
{
    int ColSum = 0;
    for (int j = 0; j < Row; j++) // لوب للصفوف
    {
        ColSum += Array[j][Col];
    }
    return ColSum;
}

void StoreSumResultsINArray (int MatrixThatHaveCols[3][3], int ArrayToFill[], short Row, short Col)
{
    for (int i = 0; i < Col; i++ )
    {
        ArrayToFill[i] = ColSum(MatrixThatHaveCols, Row, i);
    }

}

void PrintArrayResults (int ArrayFilledWithSums[3], short arrLength)
{
    for (int i = 0; i < arrLength; i++) // loop Col
    {
        cout<< "Row " << i + 1 << " Sum : " << ArrayFilledWithSums[i] << endl;
    }
}


int main ()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    int Array[3];

    Fill3x3MatrixRandomly(Matrix,3,3);
    Print3x3Matrix(Matrix, 3, 3);

    StoreSumResultsINArray(Matrix,Array, 3, 3);
    PrintArrayResults(Array,3);

    
}
