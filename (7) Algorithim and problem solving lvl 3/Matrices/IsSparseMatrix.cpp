// is the matrix sparse or not? 
// spare matrix is the matrix that have 0 more then the numbers

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
            Matrix[RowCount][ColCount] = RandomNumber(0,9);
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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            }
        }
    }
    return NumberCount;
}

bool IsSparseMatrix (int Matrix[3][3], short Row, short Col)
{
    int TotalMatrixElements = Row * Col;
    return (CountNumberInMatrix(Matrix, 0, 3, 3) >= (TotalMatrixElements / 2)); // اذا ترو رجعه
}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3] = {1, 0 ,1,
                        3, 5, 1,
                        0, 0, 0};
   /**/

   // Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "The matrix :\n";
    Print3x3Matrix(Matrix, 3, 3);

    if (IsSparseMatrix(Matrix, 3, 3) == true)
    {
        cout << "\nYes, it is a sparse\n";
    }
    else 
    {
        cout << "No, it is not a sparse\n";
    }




    

}
