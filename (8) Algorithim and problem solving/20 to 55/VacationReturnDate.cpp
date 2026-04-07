#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;

short ReadVacationDays ()
{
    short n;
    cout << "Enter Vacation Days? ";
    cin >> n; 
    return n;
}

sDate vacationEndDate (sDate vacationStart, short vacationDays)
{
    sDate vacationEnd = vacationStart;
    short DaysCounted = 0;
    // the date will increase in every loop whatever its weekend or no
    // Days count will increase just in case its not a weekend day
    while (DaysCounted <= vacationDays)
    {
        vacationEnd = IncreaseDateByOneDay(vacationEnd);
        if (!IsWeekEnd(vacationEnd))
        {
            DaysCounted++;
        }
    }
    return vacationEnd;
}
int main ()
{
    cout << "Vacation Starts:\n";
    sDate vacationStart = ReadFullDate();

    short vacationDays = ReadVacationDays();

    cout << "Return Date: ";
    PrintCurrentDate(vacationEndDate(vacationStart, vacationDays));


    return 0;
}