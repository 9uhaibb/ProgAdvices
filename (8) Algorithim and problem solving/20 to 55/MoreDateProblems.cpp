/*
OverLoad the MyDate::DayOfWeekOrder to take date structre
IsEndOfWeek
IsWeekEnd
IsBussinessDay
DaysUntilTheEndOfWeek
DaysUntilTheEndOfMonth
DaysUntilTheEndOfYear*/

#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;


bool IsEndOfWeek (sDate Date)
{
    return MyDate::DayOfWeekOrder(Date);
}

bool IsWeekEnd (sDate Date)
{
    return MyDate::DayOfWeekOrder(Date) == 5 || MyDate::DayOfWeekOrder(Date) == 6; // friday or satarday 
}

bool IsBussinessDay (sDate Date)
{
    return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek (sDate Date) 
{
    return 6 - MyDate::DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth (sDate Date)
{
    sDate EndOfMonthDate;
    EndOfMonthDate.Day = MyDate::NumberOfDaysInMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;
    return MyDate::GetDifferenceInDays(Date, EndOfMonthDate, true);
}
short DaysUntilTheEndOfYear (sDate Date)
{
    sDate EndOfMonthDate;
    EndOfMonthDate.Day = 31;
    EndOfMonthDate.Month = 12;
    EndOfMonthDate.Year = Date.Year;
    return MyDate::GetDifferenceInDays(Date, EndOfMonthDate, true);
}

int main ()
{
    sDate Date = MyDate::GetSystemDate();
    //sDate Date = MyDate::ReadFullDate();
    cout << endl;
    MyDate::PrintCurrentDate(Date);

    cout << "\nIs it End of Week?\n";
    IsEndOfWeek(Date) ? cout << "Yes it is end of week(satarday)." : cout << "No Not end of week.";

    cout << "\n\nIs it Weekend?\n";
    IsWeekEnd(Date) ? cout << "Yes it is a week end." : cout << "No Not a week end.";

    cout << "\n\nIs it Bussiness Day?\n";
    IsBussinessDay(Date) ? cout << "Yes it is bussiness day." : cout << "No Not bussiness day.";

    cout << "\n\nDays until end of Week: " << DaysUntilTheEndOfWeek(Date) << " Day(s)";
    cout << "\nDays until end of Month: " << DaysUntilTheEndOfMonth(Date) << " Day(s)";
    cout << "\nDays until end of Year: " << DaysUntilTheEndOfYear(Date) << " Day(s)";
}