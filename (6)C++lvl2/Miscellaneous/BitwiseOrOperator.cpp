#include <iostream>
using namespace std;

void Revision ()
{
    /*
    0 || 0 = 0, false and false = false
    0 || 1 = 1, false and true = true
    1 || 1 = 1, true and true = true
    */
}

int main()
{
     /*
    3 =>  00000011
    4 & =>00000100 |
    -----------------
        =>00000111 = 7 , Bit By Bit
        تقدر تعتبرها جمع للعددين بالباينري
    */
	//code [1]
    // will convert the decimal number to bindry then & the two numbers

	cout << "This is bitwise (OR) operator" << endl;
	cout << "Your number is:" << (4 | 3) << endl;
    
   
	//code [2]
	cout << "\nThis is logical (OR) operator" << endl;
	cout << "Your number is: " << (2 || 3) << endl; // 1
	cout << "Your number is: " << (-1 || -1) << endl;// 1
	cout << "Your number is: " << (0 || -1) << endl; // 1

	cout << "\nThis is logical (AND) operator" << endl;
	cout << "Your number is: " << (0 && 1) << endl; // 0
	cout << "Your number is: " << (5 && 0) << endl; // 0
	cout << "Your number is: " << (7 && 8) << endl;// 1


}