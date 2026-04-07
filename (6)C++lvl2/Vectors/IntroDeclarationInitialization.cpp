#include<iostream>
#include<vector> // <=======================================
using namespace std;

int main ()
{
    // std::vector <Type> vector_name;
    vector <int> vNumbers = {10, 20, 30, 40, 50};

    cout << "Numbers Vector = ";
    // Ranged Loop
    for (int& Number : vNumbers)
    {
        cout << Number << " ";
    }
    /* & for Number : vNumbers
    بدل ما تنسخ القيمة وتخزنها في الرقم بعدين تطبعها هيك بطيء
    &
    روح لمكانها في الذاكرة مباشرة واطبعها هيك اسرع*/
}