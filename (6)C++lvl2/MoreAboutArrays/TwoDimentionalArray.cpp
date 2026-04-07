#include<iostream>
using namespace std;

int main ()
{
    // Array Name [Rows][Columns]
    int x[3][4] = {
                    {1,2,3,4} ,
                    {5,6,7,8} ,
                    {9,10,11,12}
                  };
    // Rows Loop
    for (int r = 0; r < 3; r++)
    {
        // Cols Loop
        for (int c = 0; c < 4; c++)
        {
            cout << x[r][c] << " ";
        }
        cout << endl;
    }
}