/*fill 3*3 matrixwith random number,
then sum each row in separate array and print the results using same array*/

/*
Functions i need
1- Fill Matrix, 2- SumEachRow, 3- Store results in 1D array, 4-Print the results
5- Generate Random Number

*/

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

int SumEachRow (int Matrix[3][3], short Row, short Col)
{
    int RowSum = 0;
        for (int i = 0; i < Col; i++) // loop for Cols
        {
            RowSum += Matrix[Row][i];
        }
    return RowSum;
}

void StoreSumResultsINArray (int MatrixThatHaveRows[3][3],int ArrayToFill[], short Row, short Col)
{
    for (int j = 0; j < Row; j++ ) // loop for elements
    {
        ArrayToFill[j] = SumEachRow(MatrixThatHaveRows,j,Col);
    }
}

void PrintArrayResults (int ArrayFilledWithSums[], short Row)
{
    for (int RowCount = 0; RowCount < Row; RowCount++)
    {
        cout<< "Row " << RowCount + 1 << " Sum : " << ArrayFilledWithSums[RowCount] << endl;
    }
}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    int Array[3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);
    cout << "Matrix Elements: \n";
    Print2DArray(Matrix, 3, 3);

    StoreSumResultsINArray(Matrix, Array, 3, 3);

    cout << "Sum Each Row :\n";
    PrintArrayResults(Array, 3);
}
/*
Mistakes :
The relation btw SumEachRow Function and StoreResultInArray function
*/