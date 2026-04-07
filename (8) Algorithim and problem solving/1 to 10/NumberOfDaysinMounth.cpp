#include <iostream>

using namespace std;

short ReadYear ()
{
    cout << "Enter Year: ";
    short n; cin >> n; return n;
}

short ReadMonth ()
{
    cout << "Enter Month: ";
    short n; cin >> n; return n;
}

bool isLeapYear (short Year)
{
    return (Year % 400 ==0 || Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth (short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    else if (Month == 2)
    {
        return isLeapYear (Year) ? 29 : 28;
    }
    else
    {
        int arrMonthsWith31Days [] = {1, 3, 5, 7, 8, 10, 12};
        for (int i = 1; i <= 7; i++)
        {
            if (arrMonthsWith31Days [i] == Month)
            {
                return 31;
            }
        }
    }
    return 30;   
}


int main ()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "Number of Days in month[" << Month << "]: " << NumberOfDaysInMonth(Month, Year) << endl;
}