#include <iostream>
using namespace std;

void ReadNumbers (int &num1,int &num2) 
{
    cout << "Enter Number 1 : " ; cin >> num1;
    cout << "Enter Number 2 : " ; cin >> num2;

}
int Max2Numbers (int num1, int num2)
{
    if (num1 == num2) 
    {
        cout << "Numbers are Equal." << endl;
    }
    else if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
    
}
void PrintResult(int result)
{
    cout << "Max Number is: " << result << endl;
}
int main () 
{
   int num1, num2;
   ReadNumbers (num1,num2); 
   PrintResult(Max2Numbers(num1,num2));
}