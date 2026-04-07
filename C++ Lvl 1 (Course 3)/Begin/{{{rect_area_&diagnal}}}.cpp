#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    // 16(done) 18(done) 19(done) 20(d) 21(d) 22(d) 23(d) 31(d) 32(d) 42 43                                  
    // 16 
    /*write a program to calculate rectangle area through diagnal and side 
    area of rectangle and print it on the screen*/

    // area = a. sqr(pow(d,2)- pow (a,2))
    float high;
    float diagnal;

    cout << "Enter rectangle high : ";
    cin >> high;
    cout << "Enter rectangle diagnal : ";
    cin >> diagnal;

    float area;
    area = high * (sqrt (pow(diagnal,2) - pow(high,2)));

    cout << "the area of rectangle who has a high : "<< high << ", diagnal : " <<diagnal << ", is : " << area << endl;

    
   
   

}