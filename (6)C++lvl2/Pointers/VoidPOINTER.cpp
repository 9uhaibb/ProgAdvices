#include<iostream>
using namespace std;

int main() {
    int num = 42;
    float fnum = 3.14;
    void *ptr;
    // يمكن الإشارة إلى أي نوع من البيانات
    ptr = &num;  
    cout << "Value as an int : " << *(static_cast<int*>(ptr)) << endl;

    ptr = &fnum;  
    cout << "Value as a float : " << *(static_cast<float*>(ptr)) << endl;

    return 0;
}