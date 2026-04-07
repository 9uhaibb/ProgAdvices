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
short ReadDay ()
{
    cout << "Enter Day: ";
    short n; cin >> n; return n;
}
bool isLeapYear (short Year)
{
    return (Year % 400 == 0 || Year % 4 ==0 && Year % 100 != 0);
}
struct sDate 
{
    short Day, Month, Year;
};
sDate ReadFullDate ()
{
    sDate Date;
    Date.Day = ReadDay ();
    Date.Month = ReadMonth ();
    Date.Year = ReadYear();
    return Date;
}
bool isDate1BeforeDate2 (sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? ((Date1.Day < Date2.Day) ? true : false) : false) : false);
}
short NumberOfDaysInMonth (short Year, short Month)
{
    if (Month > 12 || Month < 1)
        return 0;
    int arrNumberOfDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];
}
bool isLastDayInMonth (sDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
bool isLastMonthInYear (sDate Date)
{
    return (Date.Month == 12);
}
sDate IncreaseDateByOne (sDate Date)
{
    if (isLastDayInMonth(Date))
    {
        if (isLastMonthInYear(Date))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else 
        {
            Date.Day =1;
            Date.Month++;
        }
    }
    else 
    {
        Date.Day++;
    }
    return Date;
}

void SwapDates (sDate& Date1, sDate& Date2)
{
    sDate tempDate;
    tempDate.Day = Date1.Day;
    tempDate.Month = Date1.Month;
    tempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = tempDate.Day;
    Date2.Month = tempDate.Month;
    Date2.Year = tempDate.Year;
}
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short swapFlagValue = 1;
    if (!isDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1,Date2);
        swapFlagValue = -1;
    }
    while (isDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOne(Date1);
    }
    return IncludeEndDay ? ++Days * swapFlagValue : Days * swapFlagValue;
}

int main ()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();

    cout << "Difference is: " << GetDifferenceInDays (Date1, Date2) << " Day(s).\n";
    cout << "Difference (including end day) is: " << GetDifferenceInDays (Date1, Date2, true)<< " Day(s).\n";
}
