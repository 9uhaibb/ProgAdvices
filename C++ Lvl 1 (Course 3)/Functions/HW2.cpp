#include <iostream>
using namespace std;

//Procedure : return nothing  ,we use just void, when we call it on the main we just write its name
//Function : return one value ,we use any variable exept void, when we call it on the main we use cout.

void MySumProcedure1()
{
    int n1,n2;
    cout << "Please Enter Number 1 : ";
    cin >> n1;

    cout << "Please Enter Number 2 : ";
    cin >> n2;
    cout << "*************************\n";

    cout << "Sum procedure " << n1+n2 << endl;
}
float MySumFunction()
{
    float n1,n2;
    cout << "Please Enter Number 1 : ";
    cin >> n1;

    cout << "Please Enter Number 2 : ";
    cin >> n2;
    cout << "*************************\n";

    return n1+n2;
}
int main ()
{
      MySumProcedure1(); 
    cout << "Function : "<< MySumFunction() << endl ;
}