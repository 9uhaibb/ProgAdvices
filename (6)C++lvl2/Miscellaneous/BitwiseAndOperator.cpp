#include <iostream>
using namespace std;

void Revision ()
{
    /*
    0 && 0 = 0, false and false = false
    0 && 1 = 0, false and true = false
    1 && 1 = 1, true and true = true
    */
}

int main()
{
        /*
    3   =>  00000011
    4 & =>  00000100 &
    -----------------
        =>  00000000 = 0 
        تقدر تعتبرها ضرب للعددين بالباينري
    */
	//code [2]

	//code [1]
    // will convert the decimal number to bindry then & the two numbers
  
	cout << "This is bitwise (AND) operator" << endl;
	cout << "2 & 8 :" << (2 & 8) << endl;
    /*2 : 00000010
      8 : 00001000 &
      = : 00000000 = 0
    */
	cout << "\nThis is logical (AND) operator" << endl;
	cout << "1 && 1 : " << (1 && 1) << endl;
	cout << "-1 && -1 : " << (-1 && -1) << endl;
	cout << "0 && -1 : " << (0 && -1) << endl;


}