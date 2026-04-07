// Fill 3 * 3 MAtrix with ordered numbers hten print it
// then transpose the Matrix and print it

/* F
1- Fill Ordered Array, 2- Print Array, 3- transpose Array
*/

#include <iostream>
using namespace std;

int Fill3x3MatrixWithOrderedNumbers (int Matrix[3][3], short Row, short Col)
{
    short Counter = 1;
    for (int i = 0; i < Row; i++)// loop for Rows
    {
        for (int j = 0; j < Col; j++) // loop for cols
        {
            Matrix[i][j] = Counter;
            Counter++;
        }
    }
    return Matrix[3][3];
}

void PrintMatrix (int Matrix[3][3],  short Row, short Col)
{
    for (int i = 0; i < Row; i++) // Loop for Rows
    {
        for (int j = 0; j < Col ; j++) // for Cols
        {
            cout << Matrix[i][j] << "        ";
        }
    cout << "\n";
    }    
}

int TransposeMatrix (int OrginalMatrix[3][3], int TransposedMatrix[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)// loop for Rows
    {
        for (int j = 0; j < Col; j++) // loop for cols
        {
            TransposedMatrix[i][j] = OrginalMatrix[j][i];
        }
    }
    return TransposedMatrix[3][3];
}

int main ()
{
    int Matrix [3][3];
    int TransposedMatrix[3][3];

    Fill3x3MatrixWithOrderedNumbers(Matrix, 3, 3);
    cout << "Orginal Matrix \n";
    PrintMatrix(Matrix, 3, 3);

    cout << TransposeMatrix(Matrix, TransposedMatrix, 3, 3);
    cout << "Transposed Matrix :\n";
    PrintMatrix(TransposedMatrix, 3, 3);

    system("pause>0");  


}