#include <iostream>
using namespace std;

int main ()
{
    float marks[3];

    cout << "Enter Grade 1 :\n";
    cin >> marks[0];
    cout << "Enter Grade 2 :\n";
    cin >> marks[1];
    cout << "Enter Grade 3 :\n";
    cin >> marks[2];
    
    cout << "*************************\n";

    float avg = (marks[0] + marks[1] + marks[2])/3;
    cout << "the average of grades is " << avg << endl;
}