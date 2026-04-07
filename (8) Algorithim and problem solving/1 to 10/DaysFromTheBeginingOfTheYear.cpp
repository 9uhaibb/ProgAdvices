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
short NumberOfDaysInMonth (short Year, short Month)
{
    if (Month > 12 || Month < 1 )
        return 0;
    int arrNumberOfDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2 ? (isLeapYear(Year)? 29 : 28) : arrNumberOfDays [Month - 1]); 
}

int DaysFromTheBeginingOfTheYear (short Day, short Month, short Year)
{
    short DaysInMonth = NumberOfDaysInMonth (Year, Month);
    short DayCount = 0;
    for (int i = 1; i < Month;i++)
    {
        DayCount += NumberOfDaysInMonth(Year, i);
    }
    DayCount += Day;
    return DayCount;
}
int main ()
{
    short Day = ReadDay(), Month = ReadMonth(), Year = ReadYear();
    cout << DaysFromTheBeginingOfTheYear(Day,Month,Year);
}