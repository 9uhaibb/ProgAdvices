#include <iostream>
using namespace std;
int main()
{
    int a = 10;

    cout << "a value        = " << a << endl;
    cout << "a address     = " << &a << endl << endl;

    int *p;
    p = &a;

    /* 
    *P or *PointerName is the same value of the variable that the pointer
    is pointing to
    */
    cout << "Pointer Value = p = " << p << endl;
    cout << "Value of the address that p is pointing to is = *p = " << *p << endl << endl;

    // and u can change it 
    *p = 20;
    cout << "*p value = " << *p << endl;
    cout << "a value  = " << a << endl << endl;

    // they have the same value because they have the same address
    a = 30;
    cout << "a value  = " << a << endl;
    cout << "*p value = " << *p << endl << endl;

    return 0;
}