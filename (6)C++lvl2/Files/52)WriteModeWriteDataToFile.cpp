#include <iostream>
#include<fstream> // <===============

using namespace std;
// run and go to the file location
// file location is the same location of this c++ code

int main ()
{
    fstream MyFile;

    MyFile.open ("MyFile.txt" , ios::out/*write code*/);  
    if (MyFile.is_open())
    {
        MyFile << "Suhaib\n";
        MyFile << "Omar\n";
        MyFile << "Erinat\n";

        MyFile.close();
    }
}