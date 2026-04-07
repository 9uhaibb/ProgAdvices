#include <iostream> 
using namespace std;

int main ()
{
    int array [4] = {10, 20, 30, 40};
     int *Pointer;
     Pointer = array;

     cout << "1) " << Pointer << endl; // point and print the first &element  in the array
     cout << "2) " <<Pointer + 1 << endl; // second &element
     cout << "3) " <<Pointer + 2 << endl; // third &element

     // or
     cout << "\n\n4) using for \n";
    for (int i = 0; i < 4; i++)
    {
        cout << "when i = " << i << ", "<< Pointer + i << endl;
    }


}