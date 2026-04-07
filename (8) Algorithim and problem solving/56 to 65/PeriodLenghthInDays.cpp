#include <iostream>
#include"MyDate.h"

using namespace std;
using namespace MyDate;

/*
int PeriodLengthInDays (sPeriod Period, bool IncludeEndDay = false)
{
    return (GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay));
}
*/
int main ()
{
    cout << "Enter Period:";
    sPeriod P1 = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLengthInDays(P1);
    cout << "\nPeriod Length(including end date) is: " << PeriodLengthInDays(P1, true);
}
