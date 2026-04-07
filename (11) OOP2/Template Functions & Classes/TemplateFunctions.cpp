#include<iostream>

using namespace std;

template <typename T> T MyMax (T Value1, T Value2 )
{
    return (Value1 > Value2) ? Value1 : Value2;
}

int main ()
{
    cout << MyMax<int> (2,5) << endl;

    cout << MyMax<float> (2.4, 5.3) << endl;

    cout << MyMax <string> ("suh", "suhaib") << endl;

    cout << MyMax<char> ('n', 'y') << endl; // compare by asci
}