#include <iostream>
using namespace std;

int main() {
    int* ptr = NULL;

    if (ptr == NULL) {
        cout << "The pointer is empty" << endl;
    } else {
        cout << "The value : " << *ptr << endl;
    }

    return 0;
}
