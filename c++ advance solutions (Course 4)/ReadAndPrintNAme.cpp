#include<iostream>
#include <string>
using namespace std;

string ReadNamee ()
{
    string name;
    cout << "Enter your name : ";
    getline(cin,name);
    return name;
}
void PrintNamee (string name) {
    cout << "Your name is : " << name << endl;

}
int main (){
    PrintNamee (ReadNamee());
}