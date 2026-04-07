// Fill 3x3 Matrix with random numbers,
// print it then print the middle row and middle col.

/*
    F
    Fill Random Matrix, 2- Generate Random Numbers
    3- Print Matrix, 4- Print Middle Row, 5- Print Middle Col
*/

#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>

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
            printf (" %0*d ", 2, Matrix[i][j]); 
        }
        cout << endl;
    }
    cout << endl;
}

void PrintTheMiddleRowOn3x3Matrix (int Matrix[3][3], short Row, short Col)
{
    short MiddleRow = Row / 2;
    for (short j = 0; j < Col; j++)
    {
        printf(" %0*d ", 2, Matrix[MiddleRow][j]);
    }
    cout << "\n";
}

void PrintTheMiddleColOn3x3Matrix (int Matrix[3][3], short Row, short Col)
{
    short MiddleCol = Col / 2;
    for (int i = 0; i < Row; i++)
    {
        printf(" %0*d ", 2, Matrix[i][MiddleCol]);
    } 
    cout << endl;
}


int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "The Matrix is : \n";
    Print3x3Matrix(Matrix, 3, 3);

    cout << "The Middle row is : \n";
    PrintTheMiddleRowOn3x3Matrix(Matrix, 3, 3);

        cout << "The Middle col is : \n";
    PrintTheMiddleColOn3x3Matrix(Matrix, 3, 3);


}