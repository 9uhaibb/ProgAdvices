#include <iostream>
using namespace std;
int main () 
{
    // *  *  *  *  *
    // *           *
    // *           *
    // *           *
    // *  *  *  *  *    

    /*
    give values
    external rows loop
    internal (nasted) columns loop
    (اكثر من شرط بنفس الوقت ||)
    */ 

   // giving values
   int rows = 5;
   int columns = 5;
   char star = '*';

   //external rows loop
   for (int i = 1 ; i <= rows ; i++)
   {
        //internal columns loop
        for (int k = 1 ; k <= columns ; k++)
        {
        if (i == 1 || k == 1 || i == 5 || k == 5)
        cout << star << "  ";
        else 
        cout << "   ";
        }
    cout << endl;    
   
   }

}
