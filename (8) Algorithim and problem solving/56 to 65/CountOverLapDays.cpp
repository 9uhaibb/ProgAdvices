#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;

int CountOverLapDays (sPeriod Period1, sPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1,true);
    int Period2Length = PeriodLengthInDays(Period2,true);
    int OverlapsDays = 0;

    if (!isOverlapPeriods(Period1,Period2))
        return 0;
    if (Period1Length < Period2Length)
    {
        while (CompareDates(Period1.StartDate, Period1.EndDate) == enDateCompare::Before)
        {
            if (isDateWithinPeriod(Period1.StartDate, Period2))
                OverlapsDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else 
    {
        while (CompareDates(Period2.StartDate,Period2.EndDate) == enDateCompare::Before)
        {
            if (isDateWithinPeriod(Period2.StartDate, Period1))
                OverlapsDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

}   

int main ()
{
    cout << "Enter Period 1:\n";
    sPeriod P1 = ReadPeriod();

    cout << "Enter Period 2:\n";
    sPeriod P2 = ReadPeriod();

    cout << "Overlap Days Count is: " << CountOverLapDays(P1,P2);

}