#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;

bool isValidateDate (sDate Date)
{
    if (Date.Day < 1 || Date.Day > 31)
        return false;
    if (Date.Month < 1 || Date.Month > 12)
        return false;
    if (Date.Month == 2)
    {
        if (isLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
        else 
        {
            if (Date.Day > 28);
                return false;
        }
    }
    short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > DaysInMonth)
        return false;
    return true;
}

int main ()
{
    cout << "Enter Date:\n\n";
    sDate Date = ReadFullDate();

    isValidateDate(Date) ? cout << "\nYes, it is validate Date." : cout << "\nNo, it is Not validate Date.";
}