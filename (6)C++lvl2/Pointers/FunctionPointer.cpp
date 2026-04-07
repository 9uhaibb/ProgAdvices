#include <iostream>
using namespace std;

// تعريف دالتين بسيطتين
void greet() {
    cout << "Hellow!" << endl;
}

void farewell() {
    cout << "Bye" << endl;
}

int main ()
{
    // initialization a function pointer
    void (*FPtr) ();
    greet();

    // Point on greet function using function pointer
    FPtr = & greet;
    FPtr (); // calling greet using function pointer

    // Point on farewall function using function pointer
    FPtr = & farewell;
    FPtr();// calling farewall using function pointer
}