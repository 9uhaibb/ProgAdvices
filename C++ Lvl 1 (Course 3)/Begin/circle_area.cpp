#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // write a prog to calculate the circle area
    /*
    circle area = pi.pow(r,2)
    pi = 3.14159
    */

    int radius;
    float pi = 3.14;

    cout << "Enter The circle radius : ";
    cin >> radius;

    float area = pi * radius * radius;
    cout << "The circla area with radius : " << radius << " is : " << area << endl;
}