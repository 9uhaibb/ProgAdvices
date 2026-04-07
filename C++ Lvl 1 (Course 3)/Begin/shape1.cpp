#include <iostream>
using namespace std;
int main ()
{
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *

    // giving values
    int rows= 5;
    int columns=5;
    char shape='*';

    for (int i=1 ; i <= rows ; i++) // this loop for (تفشق سطر)
    {
        
        for (int k = 1 ; k <=5 ; k++) // this loop to print * * * * *
        {
        cout << shape << " "; // internal  for 
        }
    cout << endl; // external for (rows count)
    }
   







    return 0;
}