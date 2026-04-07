// Print minimum and maximum numbers in matrix

/* F: FillMatrix, PrintMatrix, Minimum, Maximum*/

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
            Matrix[RowCount][ColCount] = RandomNumber(1, 100) ;
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

int MinimumNumberInMatrix (int Matrix[3][3], short Row, short Col)
{
    int Min = Matrix[0][0];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Matrix[i][j] < Min)
            {
                Min = Matrix[i][j];
            }
        }
    }
    return Min;
}

int MaximumNumberInMatrix (int Matrix[3][3], short Row, short Col)
{
    int Max = Matrix[0][0];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Matrix[i][j] > Max)
            {
                Max = Matrix[i][j];
            }
        }
    }
    return Max;

}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "Matrix :\n";
    Print3x3Matrix(Matrix , 3, 3);

    cout << "Minimum Number in the matrix : " << MinimumNumberInMatrix(Matrix, 3, 3);
    cout << "\nMaximum Number in the matrix : " << MaximumNumberInMatrix (Matrix, 3, 3);



}