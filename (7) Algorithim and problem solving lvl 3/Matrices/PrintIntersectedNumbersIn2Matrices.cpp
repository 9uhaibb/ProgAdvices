// print the intersected numbers in
// two given matrices
/*  Matrix 1 :      Matrix 2 :
1   4   9           4   66  8
4   5   9           55  7   8
7   4   2           35  7   3

Intersected numbers are:
4       7
*/

#include <iostream>
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
            Matrix[RowCount][ColCount] = RandomNumber(0, 9) ;
        }
    }
}

void Print3x3Matrix(int Matrix[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << Matrix[i][j] << "   "; 
        }
        cout << endl;
    }
    cout << endl;
}

bool IsNumberInTheMatrix (int Matrix[3][3], int Number, short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Matrix [i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintIntersectedNumbersIn2Matrices (int Matrix1[3][3], int Matrix2[3][3], short Row, short Col)
{
    int Number = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberInTheMatrix(Matrix2, Number, Row, Col))
            {
                cout << setw(3) << Number << "      ";
            }
        }
    }
}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2 [3][3];

    Fill3x3MatrixRandomly(Matrix1, 3, 3);
    Fill3x3MatrixRandomly(Matrix2, 3, 3);

    cout << "Matrix 1:\n";
    Print3x3Matrix(Matrix1, 3, 3);

    cout << "Matrix 2:\n";
    Print3x3Matrix(Matrix2, 3, 3);

    cout << "Intersected numbers are: \n";
    PrintIntersectedNumbersIn2Matrices(Matrix1, Matrix2, 3, 3);
}