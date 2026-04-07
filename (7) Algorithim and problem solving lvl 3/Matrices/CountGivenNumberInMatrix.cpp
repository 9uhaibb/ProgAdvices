// count given number in matrix

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

int CountGivenNumberInMatrix (int Matrix[3][3], int NumberToCount, short Row, short Col)
{
    int NumberCount = 0;


    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (NumberToCount == Matrix[i][j])
            {
                NumberCount++;
            }
        }
    }
    return NumberCount;
}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "The matrix :\n";
    Print3x3Matrix(Matrix, 3, 3);

    int Number = 0;
    cout << "Enter the number to count in matrix? ";
    cin >> Number;

    cout << "Number " << Number << " count in matrix is "
    << CountGivenNumberInMatrix(Matrix, Number, 3, 3) << endl;





    

}
