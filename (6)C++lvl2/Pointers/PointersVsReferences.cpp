#include <iostream>
using namespace std;
int main()
{
    // Run to understand
    int a = 10;
    int &x = a;

    cout << "1) a address : " << &a << endl ;
    cout << "2) &x = a; => " << &x << endl<< endl;

    cout << "\n3) a : " << a << endl;
    cout << "4) x : " << x << endl << endl;;

    int *p = &a;

    cout << "\n5) int *p = &a; => p = address of a : " <<  p << endl;

    cout << "6)*p = p value(value of a here) = " << *p << endl << endl;

    int b = 20;
    // Redirection p to b address (without *)
    p = &b;

    cout << "\n7)b = 20;\np = &b;\n";
    cout << "8)b address : " <<  p << endl;
    cout << "9)*p = p value(value of b here) = " << *p << endl << endl;
    return 0;
}