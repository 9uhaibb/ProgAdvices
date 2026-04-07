#include <iostream>
using namespace std;


// By Value : (without & , Will make a copy of the variable)
// By Refrance : 

void prosedure1 ( int &Num) // when i put & , Num in main will be the same Num in prosedure
// the reason is & mean address, Num has one place on memory , to reach it use &
{
    Num = 7000;
    cout << "Number inside Prosedure is : " << Num <<endl;
}
int main () // start read here
{
    int Num = 1000; //store Num = 1000
    prosedure1(Num); // call the function (print the Num)

    cout << "Number inside main is : " << Num << endl; // print the Num 
}
