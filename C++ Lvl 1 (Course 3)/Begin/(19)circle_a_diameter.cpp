#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int n;


cin>>n;


int temp = n;

int ans = 0;
cout<<  "insert the number" <<endl;
while(n>0){
int rem = n % 10;
ans = (ans) + (rem * rem * rem);
n = n / 10;
}
if (temp == ans)
{
cout<< ("Yes, it is Armstrong Number");
}
else
{
cout<< ("No, it is not an Armstrong Number");
}
return 0;

}