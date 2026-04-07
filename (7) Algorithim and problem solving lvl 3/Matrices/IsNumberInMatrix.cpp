// is number given in the matrix  or not? 

   #include<iostream>
   #include<iomanip>
   #include<ctime>
   #include"InputsLib.h"

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

bool IsNumberInTheMatrix (int Matrix[3][3], int Number, short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Matrix [i][j] == Number)
            {
                return true;
            }
        }
    }

    return false;
}

int main ()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    Fill3x3MatrixRandomly(Matrix, 3, 3);

    cout << "The matrix :\n";
    Print3x3Matrix(Matrix, 3, 3);

   int Number = InputsLib::ReadPositiveNumber("Enter a Number to search");

   if (IsNumberInTheMatrix(Matrix, Number, 3, 3))
   {
    cout << "Yes, the number is in the matrix.\n";
   }
   else
   {
    cout << "No, the number is not there.\n";
   }
    

}
