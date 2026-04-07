#include<iostream>
#include<cstdio>
using namespace std;

int main ()
{
    int Arr[10][10];
    int Result [10][10];

    for (int r = 0; r <= 9; r++)
    {
        for (int c = 0; c <= 9 ; c++)
        {
            Result[r][c] = (r + 1) * (c + 1)/*adding 1 tp skip the 0 vslues*/;
        }
    }
    // printing

    for (int r = 0; r <= 9; r++)
    {
        for (int c = 0; c <= 9; c++)
        {
            printf("%0*d ",2, Result[r][c]);
        }
        cout << endl;
    }
}