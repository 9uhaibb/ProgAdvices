#include <iostream>
using namespace std;

// Benefits of using dynamic pointers:
// 1. Allow memory allocation during runtime based on actual needs.
// 2. Provide flexibility to allocate memory with an undefined size beforehand.
// 3. Give full control over memory lifetime (manual allocation and deallocation).
// 4. Useful in large applications or scenarios requiring variable-sized memory.


int main() {
    // تخصيص ذاكرة ديناميكيًا
    int *ptr = new int;
    *ptr = 20;

    cout << "The value : " << *ptr << endl;

    // تحرير الذاكرة
    delete ptr;

    // example 2:
    cout << "example 2:\n";

    int* ptr2 = new int; // تخصيص ديناميكي
    
    cout << "Enter number: ";
    cin >> *ptr2; // تخزين القيمة المدخلة في الذاكرة المخصصة
    
    cout << "stored number : " << *ptr2 << endl;
    delete ptr2; // تحرير الذاكرة

    return 0;
}
