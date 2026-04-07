#include<iostream>
using namespace std;

int ReadNumber(string);


int main ()
{
    int number = ReadNumber("Enter ...");
    cout <<"Your number is : " << number << endl;
}

int ReadNumber(string Massege )
{
    cout << Massege << endl;
    int Number ;
    cin >> Number;

    return Number;

}

