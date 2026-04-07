#include <iostream>
#include <string>

using namespace std;

void UrName() {
    string name;
    cout << "Enter your name to print it on the screen:\n";
    getline(cin, name);
    cout << "Your Name is: " << name << endl;
}

int main() {
    UrName(); // Call the function
    return 0;
}
