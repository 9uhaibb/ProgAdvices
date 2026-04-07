// Fill two 3x3 Matrix with random numbers
// then multiply them into a 3rd Matrix and print it.

/* F:
1- Fill Matrix with Random Numbers, 2- Generate Random Numbers
3- Print Matrix, 4-Multiply 2 Matrixes into 3rd One
*/

#include<iostream>
#include<iomanip>
#include<ctime>

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
            Matrix[RowCount][ColCount] = RandomNumber(1,10);
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

int MultiplyTwoMatrixesInto3rdOne (int MatrixOne [3][3], int MatrixTwo [3][3],int ResultsMatrix [3][3], int Row, int Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            ResultsMatrix[i][j] = MatrixOne[i][j] * MatrixTwo[i][j];
        }
    }
    return ResultsMatrix[3][3];
}

int main ()
{
    srand((unsigned)time(NULL));

    int MatrixOne [3][3], MatrixTwo [3][3], MultiplyTowMatrixesResults [3][3];

    Fill3x3MatrixRandomly (MatrixOne, 3, 3);
    Fill3x3MatrixRandomly(MatrixTwo, 3, 3);

    cout << "\nMatrix 1 : \n";
    Print3x3Matrix(MatrixOne, 3, 3);

    cout << "Matrix 2 : \n";
    Print3x3Matrix(MatrixTwo, 3, 3);

    MultiplyTwoMatrixesInto3rdOne(MatrixOne, MatrixTwo, MultiplyTowMatrixesResults, 3, 3);

    cout << "Multiply the two matrixes : \n";
    Print3x3Matrix(MultiplyTowMatrixesResults, 3, 3);

    
}