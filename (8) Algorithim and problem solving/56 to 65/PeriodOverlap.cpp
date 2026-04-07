#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;

/*struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
};

if Period 1 End before Period 2 Start, so there is no overlap
id Period 1 Strat After Period 2 End, so there is no overlap

bool isOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
    return !(CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before
          || CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After);
}

sPeriod ReadPeriod()
{
    sPeriod Period;
    cout << "\nEnter Start Date:\n\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n\n";
    Period.EndDate = ReadFullDate();
    return Period;
}*/
int main()
{
    cout << "\nEnter Period 1:";
    sPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    sPeriod Period2 = ReadPeriod();

    if (isOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";
    system("pause>0");
    return 0;
}
