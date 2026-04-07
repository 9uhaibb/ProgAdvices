#include<iostream>
using namespace std;
int main()
{
 //fractional of any integer
 int x;
 long long factorial =1;
 cout << "enter any integer \n";
 cin >> x;

 if (x<0)
 cout <<"wrong value, try again";
 else 
 for (int i=1;i<=x;i++)
 {
    factorial*= i;
   
 }
cout << "factorial of " << x << " is "<< factorial << endl; 




}//end main.