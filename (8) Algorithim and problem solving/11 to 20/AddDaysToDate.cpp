#include <iostream>

using namespace std;

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
int ReadDaysToAdd ()
{
    cout << "How Many Days to Add? ";
    int n; cin >> n; return n;
}
bool isLeapYear (int Year)
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
short DaysFromTheBeginingOfTheYear (short Day, short Month, short Year)
{
    short DayCount = 0;
    for (int i = 1; i < Month;i++)
    {
        DayCount += NumberOfDaysInMonth(Year, i);
    }
    DayCount += Day;
    return DayCount;
}

struct sDate 
{
    short Day;
    short Month;
    short Year;
};
sDate ReadFullDate ()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth ();
    Date.Year = ReadYear();
    return Date;
}

sDate AddDaysToDate (short DaysToAdd, sDate Date)
{
    short RemainingDays = DaysToAdd + DaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    
    while (RemainingDays > 0)
    {
        MonthDays =  NumberOfDaysInMonth(Date.Year, Date.Month);
        if (RemainingDays >  MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else 
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
int main ()
{
    sDate Date = ReadFullDate();
    int DaysToAdd = ReadDaysToAdd ();

    Date = AddDaysToDate (DaysToAdd, Date);
    cout << "\nDate after adding [" << DaysToAdd << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
    }