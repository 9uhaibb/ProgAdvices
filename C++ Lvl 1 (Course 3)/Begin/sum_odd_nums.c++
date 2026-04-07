#include <iostream>
using namespace std;
int main () 
{
    // Write a program that find the sum of odd numbers from 1 to 20.
    
    //odd = i will use if statment ,num %2 != 0 is odd
    // from 1-20 = i will use (for/while/do while) loop
    //variables : integers 

    int num=0;
    int sum=0;
    for (int i =1 ; i<=20 ; i++)
    {
        if (i%2 !=0)
        {
            cout << i << endl;
            sum = sum+i;
        }
    }
    cout << "the sum of odd nums from 1-20 is : "<< sum << endl;



}