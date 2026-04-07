// Fill 3 * 3 MAtrix with ordered numbers hten print it

/* F
1- Fill Array, 2- Print Array
*/

#include <iostream>
using namespace std;

int Fill3x3MatrixWithOrderedNumbers (int Matrix[3][3], short Row, short Col)
{
    short OrderedNumbers = 1;
    for (int i = 0; i < Row; i++)// loop for Rows
    {
        for (int j = 0; j < Col; j++) // loop for cols
        {
            Matrix[i][j] = OrderedNumbers;
            OrderedNumbers++;
        }
    }
    return Matrix[3][3];
}

void PrintMatrix (int Matrix[3][3], short Row, short Col)
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

int main ()
{
    int Matrix [3][3];

    Fill3x3MatrixWithOrderedNumbers(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);

    system("pause>0");  


}