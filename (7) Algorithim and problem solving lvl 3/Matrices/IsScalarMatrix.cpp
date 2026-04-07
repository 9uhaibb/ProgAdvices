// check if the matrix is scalar or not
/*scalar  5  0  0
          0  5  0
          0  0  5 ,  5 or any number */

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

bool IsScalarMatrix (int Matrix [3][3], short Row, short Col)
{
    int FirstElement = Matrix[0][0];

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if ( i == j /*diagonal position*/ && Matrix[i][j] != FirstElement)
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0)
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

    int Matrix[3][3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "The matrix :\n";
    Print3x3Matrix(Matrix, 3, 3);

    if (IsScalarMatrix(Matrix, 3, 3))
        cout << "Yes, it is a Scale matrix.\n";
    else
        cout << "No, it is not a Scale matrix.\n";   



    

}
