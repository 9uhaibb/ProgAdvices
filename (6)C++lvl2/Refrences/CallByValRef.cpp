#include <iostream>

using namespace std;

void F1 (int  x)
{
    x++;
}

int main ()
{
    int a = 10; 
    F1(a);
    cout << a << endl;
}