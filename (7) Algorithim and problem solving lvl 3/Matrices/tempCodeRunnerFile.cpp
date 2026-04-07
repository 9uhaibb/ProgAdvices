// fill 2 3x3 matrix with random numbers,
// then check if the sum of the 2 matrix are equal or not(print the result)
//

/* F:
    Fill matrix with random numbers. 2- g Random numbers.
    3- Sum all numbers on the matrix. 4- print the matrix, 5- check if sum equal
    */

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill3x3MatrixRandomly(int Matrix[3][3], short Row, short Col)
{
    for (int RowCount = 0; RowCount < Row; RowCount++)
    {
        for (int ColCount = 0; ColCount < Col; ColCount++)
        {
            Matrix[RowCount][ColCount] = RandomNumber(1, 10);
        }
    }
}

void Print3x3Matrix(int Matrix[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            printf(" %0*d ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int SumMatrix(int Matrix[3][3], short Row, short Col)
{
    int Sum = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}

bool Are2MatricesEqual(int MatrixOne[3][3], int MatrixOTwo[3][3], short Row, short Col)
{
    return (SumMatrix(MatrixOne, Row, Col) == SumMatrix(MatrixOTwo, Row, Col));
    //  اذا المصفوفتين متساويتين رجّع ترو
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];

    Fill3x3MatrixRandomly(Matrix1, 3, 3);
    Fill3x3MatrixRandomly(Matrix2, 3, 3);

    cout << "Matrix 1 is : \n";
    Print3x3Matrix(Matrix1, 3, 3);
    cout << "Matrix 2 is : \n";
    Print3x3Matrix(Matrix2, 3, 3);

    if (Are2MatricesEqual(Matrix1, Matrix2, 3, 3) /*if true*/)
    {
        cout << "Both are equal.\n";
    }
    else
    {
        cout << "Both aren't equal\n";
    }
}
