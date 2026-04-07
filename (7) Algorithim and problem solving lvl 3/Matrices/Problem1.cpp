// print random 3 * 3 array
#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void Fill2DArrayWithRandomNumbers(int Array[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            Array[i][j] = RandomNumber(1, 100);
        }
    }
}

void Print2DArray(int Array[3][3], short Row, short Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << setw(3) << Array[i][j] << "  "; 
        }
        cout << endl;
    }
}

int main()
{
    //Seeds the random number generator in c++
    srand((unsigned)time(NULL));

    int Array[3][3];

    Fill2DArrayWithRandomNumbers(Array, 3, 3);
    Print2DArray(Array ,3 ,3);
}

// My Mistakes:
/*
didint put short(Row,Col) in the Functions
for (int Row = 0; Row < 3; Row++) This is true but not genaric (just for 3*3)
didn't use setw(x) (From <iomanip> Lib) while Printing
*/