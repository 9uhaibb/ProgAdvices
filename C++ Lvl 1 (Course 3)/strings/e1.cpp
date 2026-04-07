#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string string1;
    string string2;
    string string3;

    cout << "please enter string 1 : ";
    //somtimes getline will ignore the cin from the user,(compiler think user entered so string 1 still inane فارغ)
    //to solve this write :
    // cin.ignore(1, '\n' );
    getline(cin,string1);

    cout << "please enter string 2 (number) : ";
    cin >> string2;
    
    cout << "please enter string 3 (number) : ";
    cin >> string3;

    cout << "The Lenth of string1 is : " << string1.length() << endl;
    cout << "Charecters at 0,2,4,7 is : " << string1[0] << string1[2] << string1[4]<< string1[7] << endl;
    cout << "Concatenation string 2 and string 3 is :  " << string2 + string3 << endl;
    
    int num1 = stoi(string2);
    int num2 = stoi(string3);
    cout<<"5*10 = "<< num1 * num2<< endl;


  
}