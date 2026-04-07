#include<iostream>

using namespace std;

int main ()
{
    // pointer is a variable that can stoarge just addresses from 
    // other variables
    int a = 10;
    int b = 20;

    // decleration the pointer : the same type of the address variable

    /* syntax :
    type(int, or any) * PointerName = &variable
    */
    int * P = &a;
    cout << "1) a = " << a << endl;

    cout << "\n2) a address = " << &a << endl;
    cout << "3) a pointer or P  = " << P << endl;

    // change pointer direction to another variable address
    P = &b;

    cout << "\n4) a = " << a << endl;
    cout << "5) b = "<< b << endl;

    cout << "\n6) a address = " << &a << endl;
    cout << "7) b address = " << &b << endl;

    cout << "\n9) Pointer P or address after changing direction to b = " << P << endl;
    

}