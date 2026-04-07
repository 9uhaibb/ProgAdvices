/* check if the 3x3 matrix is identity or not
identitny matrix : 1  0  0
                   0  1  0
                   0  0  1*/

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

bool IsIdentityMatrix (int Matrix[3][3],short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if ( i == j /*diagonal position*/ && Matrix[i][j] != 1)
            {
                return false;
            }
            else if ( i != j && Matrix[i][j] != 0)
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
    /*int Matrix2 [3][3] = {1, 0, 0,
                          0, 1, 0,
                          0, 0, 1}; */

    cout << "The matrix :\n";
    Print3x3Matrix(Matrix, 3, 3);


    if (IsIdentityMatrix(Matrix, 3, 3))
        cout << "Yes, it is an identity matrix.\n";
    else
        cout << "No, it is not an identity matrix.\n";   

    

}
