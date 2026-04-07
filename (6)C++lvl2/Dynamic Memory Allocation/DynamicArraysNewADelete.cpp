#include<iostream>
using namespace std;

int main ()
{
    int NumOfStudents;
    cout << "Enter the number of students? \n";
    cin >> NumOfStudents;

    float * ptr;

    ptr = new float [NumOfStudents];

    cout << "\nEnter Grades of student below : \n";

    for(int i = 0; i < NumOfStudents; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> *(ptr + i); // +i cuz its an array
    }
    cout << "\nDisplaying the grades \n";
    for (int i = 0 ; i < NumOfStudents; i++)
    {
        cout << "Student "<< i + 1 << ": ";
        cout << *(ptr + i) << endl;
    }

    delete [] ptr;


}