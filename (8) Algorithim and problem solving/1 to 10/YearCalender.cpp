#include <iostream>
using namespace std;

short ReadYear ()
{
    cout << "Enter Year: ";
    short n; cin >> n; return n;
}
bool isLeapYear (short Year)
{
    return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 !=0);
}

short NumberOfDaysInMonth (short Year, short Month)
{
    if (Month > 12 || Month < 1 )
        return 0;
    int arrNumberOfDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2 ? (isLeapYear(Year)? 29 : 28) : arrNumberOfDays [Month - 1]); 
}
short DayOfWeekOrder (short Day, short Month, short Year) // return the day index in a specific Year & month
{
    int a = 0, d = 0, m = 0, y = 0;
    a = (14 - Month) / 12 ;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0: Sun, 1 : Mon,...etc
    return (Day + y  + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName (short DayIndex)
{
    // Gregorian:
    // 0: Sun, 1 : Mon,...etc
    string arrDayName [] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    return arrDayName[DayIndex];
}
string MonthShortName (short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar",
                          "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep",
                          "Oct", "Nov", "Dec"};
return (Months[MonthNumber - 1]);
}

void PrintMonthCalender (short Month, short Year)
{
    int NumberOfDays = NumberOfDaysInMonth (Year,Month);
    int current = DayOfWeekOrder (1, Month, Year); // return the first day order in a month

    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i = 0;
    for (; i < current; i++) // print spaces until reach to before the first day of the month
        printf("     "); // 5 spaces
    // out of the loop, i = current
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j); // print j after 5 spaces
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
}
void PrintYearCalender (short Year)
{
    printf("\n  _________________________________\n\n");
    printf("            Calender - %d", Year);
    printf("\n  _________________________________\n");
    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalender(i,Year);
        printf("\n");
    }
    return;
}

int main ()
{
    short Year = ReadYear ();
    PrintYearCalender(Year);
    
}