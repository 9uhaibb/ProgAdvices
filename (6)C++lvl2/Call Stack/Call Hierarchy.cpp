#include<iostream>
using namespace std;

void Function4 () {
     // Debug From Here,
     // and Right click on the function,
     // then go to show Hirarchy to understand.
cout << "Hi, I'm Function 4!" << endl;
}

void FunctionThree () 
{
    Function4();
}

void Function2 ()
{
    FunctionThree () ;
}

void Function1 ()
{
    Function2();
}

int main (){
    Function1 ();
}