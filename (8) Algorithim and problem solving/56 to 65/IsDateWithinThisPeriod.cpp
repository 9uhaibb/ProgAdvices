#include <iostream>
#include"MyDate.h"

using namespace std;
using namespace MyDate;
/*
bool isDateWithinPeriod (sDate Date, sPeriod Period)
{
    return !(CompareDates(Date,Period.StartDate) == enDateCompare::Before 
            || CompareDates(Date,Period.EndDate) == enDateCompare::After);
}
*/
int main ()
{
    cout << "Enter Period:\n";
    sPeriod Period = ReadPeriod();

    cout << "\nEnter Date to check:\n";
    sDate Date = ReadFullDate();

    if (isDateWithinPeriod (Date, Period))
        cout << "\nYes, Date within this period.";
    else 
        cout << "\nNo, Date is not within this period.";

    system("pause>0");
    return 0;
}