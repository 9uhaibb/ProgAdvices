// compare 2 matrices and check if they are
// typical or not

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
            //printf (" %0*d ", 2, Matrix[i][j]); 
            cout << setw(3) << Matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool Are2MatricesTypical (int MatrixOne[3][3], int MatrixOTwo[3][3] , short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (MatrixOne[i][j] != MatrixOTwo[i][j])
            {
                return false;
            }
        } 
    }
    return true;
}

int main ()
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

    if (Are2MatricesTypical(Matrix1, Matrix2, 3, 3) /*if true*/)
    {
        cout << "Both are typical\n";
    }
    else
    {
        cout << "Both aren't typical\n";
    }
}
