#include <iostream>
using namespace std;

void Swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main ()
{
    int a = 1,  b = 2;

    cout << "Numbers before swap : ";
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    Swap(&a, &b);

    cout << "Numbers after swap : ";
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;



}