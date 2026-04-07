// fill  3x3 matrix with random numbers and then write a function to sum all numbers 
// on that matrix and print the sum

/* F: 
    Fill matrix with random numbers. 2- g Random numbers.
    3- Sum all numbers on the matrix. 4- print the matrix, 5- print the sum
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
            printf (" %0*d ", 2, Matrix[i][j]); 
        }
        cout << endl;
    }
    cout << endl;
}

int SumNumbersInMatrix (int Matrix[3][3], short Row, short Col)
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

void PrintSumNumbersInMatrix (int Sum)
{
    cout << "The Sum of the Matrix is : " << Sum << endl;
}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "The Matrix is : \n";
    Print3x3Matrix(Matrix, 3, 3);

    PrintSumNumbersInMatrix(SumNumbersInMatrix(Matrix, 3, 3));

}
  