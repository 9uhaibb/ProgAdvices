#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    //a prog to cal area of circle inscribed on sqr
    //sqr tall called A
    // the user enter A
    //دائرة داخل مربع
    float A;
    float r;

    cout << "Enter the sqr tall (A)";
    cin >> A;

    r=A/2; // القطر يساوي طول الضلع -نصف القطر يساوي نصف الضلع 
    float pi =3.14;
    float area= pi*pow(r,2);

    cout << area << endl;
}