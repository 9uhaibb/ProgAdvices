#include <iostream>
using namespace std;

struct sDate
{
    short Day, Month, Year;
};
short ReadDay ()
{
    cout << "Enter Day: ";
    short n; cin >> n; return n;
}
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
sDate ReadFullDate ()
{
    sDate Date;
    Date.Day = ReadDay ();
    Date.Month = ReadMonth ();
    Date.Year = ReadYear();
    return Date;
}
bool isLeapYear (short Year)
{
    return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInMonth (short Year, short Month)
{
    if (Month > 12 || Month < 1)
        return 0;
    int arrNumberOfDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];
}

bool isLastDayInMonth(sDate Date)
{
    return (NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day);
}
bool isLastMonthInYear (sDate Date)
{
    return (Date.Month == 12);
}
int main ()
{
    sDate Date = ReadFullDate ();
    if (isLastDayInMonth(Date))
        cout << "Yes, " << Date.Day << " is the last day on this month.\n";
    else 
        cout << "No, " << Date.Day << " is'nt the last day on this month.\n";
    if (isLastMonthInYear(Date))
        cout << Date.Month << " is the last month on this year.\n";
    else 
        cout << Date.Month << " is'nt the last month on this year.\n";
    }