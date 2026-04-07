#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  //محيط الدائرة= l^2/(4*pi)
  float L ;
  

  cout << "enter the lenth of boundary of the circle";
  cin >> L;
  float pi =3.14;

  float area = (L*L)/(4*pi);

  cout << "area is : "<< area << endl;   
}