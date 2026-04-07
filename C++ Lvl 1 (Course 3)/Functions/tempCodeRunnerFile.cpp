#include <iostream>
using namespace std;


int x = 100;
void presedure1()
{
    int x = 10;
    cout << "The value inside the presedure is : " << x << endl;
}
int function1()
{
    int x = 50;
    cout << "The value inside the function is : " << x << endl;
    presedure1();
    cout << "The global value of x  is : " << ::x << endl;
    return 0;
}