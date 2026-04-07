#include<iostream>
using namespace std;

enum enDayOfWeek {Sunday = 1, Monday = 2, TuesDay = 3, WednesDay = 4, Thursday = 5,Friday = 6, Saturday = 7};

int ReadNumberInRange (string massege, int from, int to)
{
    int number = 0;
    do 
    {
        cout << massege << endl;
        cin >> number;
    } while (number < from || number > to);
}

enDayOfWeek ReadDayOfWeek ()
{
    return (enDayOfWeek)ReadNumberInRange("Enter number of day?",1,7);
}

string PrintDayOfWeek (enDayOfWeek day)
{
    switch (day)
    {
        case enDayOfWeek::Sunday:
             return "its Sunday.\n";
        case enDayOfWeek::Monday: 
             return "its Monday.\n";
        case enDayOfWeek::TuesDay: 
             return "its TuesDay.\n";
        case enDayOfWeek::WednesDay:
             return "its WednesDay.\n";
        case enDayOfWeek::Thursday: 
             return "its Thursday.\n";
        case enDayOfWeek::Friday: 
             return "its Friday.\n";
        case enDayOfWeek::Saturday:
             return "its Saturday.\n";
        default :
        return "Invalid input ,Try again and choose between 1-7";
    }
}

int main ()
{
    cout << PrintDayOfWeek(ReadDayOfWeek()); 
}