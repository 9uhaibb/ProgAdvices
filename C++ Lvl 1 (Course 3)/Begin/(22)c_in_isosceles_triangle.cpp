#include <iostream>
#include <cmath>

using namespace std;

int main()
{ 
    // دائرة داخل مثلث متساوي الساقين
    //area = pi *(b^2/4) * ((2*(a-b))/(2*(a+b)))

    int a;
    int b;

    cout << "enter a : ";
    cin >>a;

    cout << "enter b : ";
    cin >> b;

    float pi =3.14;
    float  area =(pi*b*b/4) * ((2*a-b)/(2*a+b));

    cout << "area : " << area;
}