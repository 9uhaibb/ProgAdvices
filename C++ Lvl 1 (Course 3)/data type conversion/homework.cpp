#include <iostream>
#include <string>

using namespace std;

int main ()
{
    // convert string st1 ="43.22" to double, float and int
    string st1 = "43.22";

    double num_double = stod(st1);
    float num_float = stof(st1);
    int num_int = stoi(st1);

    cout << "num double : " << num_double << endl; 
    cout << "num float : " << num_float << endl; 
    cout << "num int : " << num_int << endl; 

    //convert int n=20 to string 
    int n = 20;
    double n2 = 40;
    string stn, stn2;
    stn = to_string(n);
    stn2 = to_string(n2);

    cout << n << endl << n2 << endl;

    // convert float n3 = 55.54 to string and int
    float n3 = 55.54;
     // to string
     string st3;
     st3 = to_string(n3);
     //to int
      int num2_int = int(n3);

      cout << "string : " << st3 << endl;
      cout << "num int : " << num2_int << endl;

}