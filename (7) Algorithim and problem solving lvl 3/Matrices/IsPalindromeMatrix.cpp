/*A 3x3 palindrome matrix is one in which each row and each column
 reads the same forward and backward
 1  2  1
 2  3  2
 1  2  1
 */
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // printf(" %0*d ", 2, arr[i][j]);
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    // Check if each row is palindromic
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            // Row i: [a11, a12, a13]
            //          ^         ^
            //     Compare a11 and a13
            //
            // Row 1: [1, 2, 1]
            //         ^     ^
            // Row 2: [5, 5, 5]
            //         ^     ^
            // Row 3: [7, 3, 7]
            //         ^     ^
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
            {
                return false; // If any row is not palindromic, return false
            }
        }
    }

    // Check if each column is palindromic
    for (short j = 0; j < Cols; j++)
    {
        for (short i = 0; i < Rows / 2; i++)
        {
            // Column j:
            // a11
            //  |
            // a21    -> Compare a11 and a31
            //  |
            // a31
            //
            // Column 1: [1, 5, 7]
            //            ^     ^
            // Column 2: [2, 5, 3]
            //            ^     ^
            // Column 3: [1, 5, 7]
            //            ^     ^
            if (Matrix1[i][j] != Matrix1[Rows - 1 - i][j])
            {
                return false; // If any column is not palindromic, return false
            }
        }
    }

    return true; // If all rows and columns are palindromic, return true
}
int main()
{
    int Matrix1[3][3] = {{1, 2, 1}, {2, 3, 2}, {1, 2, 1}};

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
        cout << "\nNo: Matrix is Not Palindrome\n";

    system("pause>0");
}