#include <iostream>
using namespace std;

int x = 100;

void procedure() {
    int x = 10;
    cout << "The value inside the procedure is: " << x << endl;
}

int function() {
    int x = 50;
    cout << "The value inside the function is: " << x << endl;
    return 0;
}

int main() {
    procedure();
    function();
    cout << "The global value of x is: " << ::x << endl;
    return 0;
}
