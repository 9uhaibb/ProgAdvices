#include <iostream>
using namespace std;


void ReadGrades (float grade[3])
{
    cout << "Enter Grade 1:\n";
    cin >> grade[0];
    cout << "Enter Grade 2:\n";
    cin >> grade[1];
    cout << "Enter Grade 3:\n";
    cin >> grade[2];
    
}
float CalculateAvgGrades (float grade[3])
{
    return (grade[0] + grade[1] + grade[2])/3;
}

int main ()
{
    float grade[3];
    ReadGrades(grade);
    cout << "******************** \n";
    cout << "grades average : " << CalculateAvgGrades( grade);
    cout << "******************** \n";
}