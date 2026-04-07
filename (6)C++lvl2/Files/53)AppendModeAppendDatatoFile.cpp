#include <iostream>
#include<fstream> // <===============

using namespace std;
// run and go to the file location
// file location is the same location of this c++ code

// The differance btw out, append or write mode and append mode
/*
    out (write mode)
    clear the previous data type on the file and inputs what u need
    syntax :    ios::out

    app (append mode)
    add data type to the previous data type that u already input it
    syntax :    ios:: app 
             or ios::out | ios::app

    try run in the two cases (run more than 1 time then open the file and see)
*/

int main ()
{
    fstream MyFile;

    MyFile.open ("MyFile.txt" , ios::out | ios::app);  
    if (MyFile.is_open())
    {
        MyFile << "Suhaib\n";
        MyFile << "Omar\n";
        MyFile << "Erinat\n";
        MyFile << "Hi, this is a new line\n";

        MyFile.close();
    }
}