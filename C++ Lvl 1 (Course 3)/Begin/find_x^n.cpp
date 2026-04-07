#include <iostream>
using namespace std;
int main () 
{
  float base , result =1;
  int power;

  cout << "Enter the base (x) :";
  cin >> base;

  cout << "Enter the power of the base (n) : ";
  cin >> power;

  while (power != 0)
  {
    result*=base;
    --power;
  }
   cout << "the base "<< base << "to the power of "<<power<< " is equal : "  <<result <<endl; 
    
}