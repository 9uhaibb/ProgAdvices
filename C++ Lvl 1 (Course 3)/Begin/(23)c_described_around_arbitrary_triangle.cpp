#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   // prog to calculate circle area , circle described
   // around an arbitrary triangle
   //مساحة دائرة داخلها مثلث ولا ضلع يساوي الاخر
   // user entet a, b, c
   float a, b, c;
   cout << "enter a:";
   cin >> a;
   cout << "enter b:";
   cin >> b;
   cout << "enter c:";
   cin >> c;

   float p;
   p= (a+b+c)/2;
   float pi=3.14;
   float area;
   area=3.14*pow((a*b*c/(4*sqrt(p*(p-a)*(p-b)*(p-c)))),2);
   cout << area << endl;






}