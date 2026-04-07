/*
1.DecreasDateByOneDate done
2.DecreaseDateByXDays done
3.DecreaseDateByOneWeek done
4.DecreaseDateByXWeeks  done
5.DecreaseDateByOneMonth  done
6.DecreaseDateByXMonth  done
7.DecreaseDateByOneYear  done
8.DecreaseDateByXYears  
9.DecreaseDateByXYearsFaster  
10.DecreaseDateByOneDecade  
11.DecreaseDateByXDecades  
12.DecreaseDateByXDecadesFaster  
13.DecreaseDateByOneCentury 
14.DecreaseDateByOneMillennium
*/
#include <iostream>
#include "MyDate.h"

using namespace MyDate;
using namespace std;

bool isFirstDayInMonth (sDate Date)
{
    return Date.Day == 1;
}
bool isFirstMonthInYear (sDate Date)
{
    return Date.Month == 1;
}

//1.DecreasDateByOneDate 
sDate DecreaseDateByOneDay (sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month)
        {
            if (Date.Year == 1)
            {
                cout << "Date cannot decreased 1 in case year is 1";
            }
            else
            {
            Date.Month = 12;
            Date.Year--;
            Date.Day = 31;
            }
        }
        else 
        {
            Date.Month--;
            Date.Day = MyDate::NumberOfDaysInMonth(Date.Year,Date.Month);
        }
    }
    else 
    {
        Date.Day--;
    }
    return Date;
}
//2.DecreaseDateByXDays 
sDate DecreaseDateByXDays (sDate Date, short Days)
{
    for (int i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
//3.DecreaseDateByOneWeek 
sDate DecreaseDateByOneWeek (sDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
//4.DecreaseDateByXWeeks 
sDate DecreaseDateByXWeeks (sDate Date, short Weeks)
{
    for (int i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
} 
//5.DecreaseDateByOneMonth  
sDate DecreaseDateByOneMonth (sDate Date)  
{
    if (Date.Month == 1)
    {
        if (Date.Year == 1)
        {
            cout << "Date cannot decreased by 1 more month in case year is 1 and month is 1";
        }
        else 
        {
        Date.Year--;
        Date.Month = 12;
        }
    }
    else 
    {
        Date.Month--;
    }
    // different months have different Number of days
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;

}
//6.DecreaseDateByXMonth  
sDate DecreaseDateByXMonths (sDate Date, short Months)
{
    for (int i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
} 
//7.DecreaseDateByOneYear  
sDate DecreaseDateByOneYear (sDate Date)
{
    if (Date.Year == 1)
    {
        cout << "Date cannot decreased 1 in case year is 1";
    }
    else 
    {
        Date.Year--;
    }
    return Date;
}
//8.DecreaseDateByXYears  
sDate DecreaseDateByXYears (sDate Date, short Years)
{
    for (int i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
//9.DecreaseDateByXYearsFaster  
sDate DecreaseDateByXYearsFaster (sDate Date, short Years)
{
    Date.Year -= Years;
    if (Date.Year < 0)
    {
        cout << "Date cannot decreased in case year is less then 0";
    }
    return Date;
}
//10.DecreaseDateByOneDecade 
sDate DecreaseDateByOneDecade (sDate Date)
{
    if (Date.Year <= 10)
    {
        cout << "Date cannot decreased less than 1 year";
    }
    else 
    {
        Date.Year-= 10;
    }
    return Date;
}
//11.DecreaseDateByXDecades 
sDate  DecreaseDateByXDecades (sDate Date, short Decades)
{
    for (int i = 1; i <= Decades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
//12.DecreaseDateByXDecadesFaster  
sDate DecreaseDateByXDecadesFaster (sDate Date, short Decades)
{
    if (Date.Year <= 10)
    {
        cout << "Date cannot decreased less than 1 year";
    }
    else 
    {
        Date.Year -= 10 * Decades;
    }
    return Date;
}
//13.DecreaseDateByOneCentury 
sDate DecreaseDateByOneCentury (sDate Date)
{
    if (Date.Year <= 100)
    {
        cout << "Date cannot decreased less than 1 year";
    }
    else 
    {
        Date.Year-= 100;
    }
    return Date;
}
//14.DecreaseDateByOneMillennium
sDate DecreaseDateByOneMillennium (sDate Date)
{
    if (Date.Year <= 1000)
    {
        cout << "Date cannot decreased less than 1 year";
    }
    else 
    {
        Date.Year -= 1000;
    }
    return Date;
}

int main ()
{
    sDate Date = MyDate::ReadFullDate();

    cout << "\nDate After:\n";

    cout << "1.Decreasing One Day is: ";
    Date = DecreaseDateByOneDay(Date);
    MyDate::PrintDate(Date);

    cout << "2.Decreasing 10 Day is: ";
    Date = DecreaseDateByXDays(Date,10);
    MyDate::PrintDate(Date);

    cout << "3.Decreasing One Week is: ";
    Date = DecreaseDateByOneWeek(Date);
    MyDate::PrintDate(Date);

    cout << "4.Decreasing 10 Weeks is: ";
    Date = DecreaseDateByXWeeks(Date,10);
    MyDate::PrintDate(Date);

    cout << "5.Decreasing One Month is: ";
    Date = DecreaseDateByOneMonth(Date);
    MyDate::PrintDate(Date);

    cout << "6.Decreasing 5 Months is: ";
    Date = DecreaseDateByXMonths(Date,5);
    MyDate::PrintDate(Date);

    cout << "7.Decreasing One Year is: ";
    Date = DecreaseDateByOneYear(Date);
    MyDate::PrintDate(Date);

    cout << "8.Decreasing 10 Years is: ";
    Date = DecreaseDateByXYears(Date,10);
    MyDate::PrintDate(Date);

    cout << "9.Decreasing 10 Years(faster) is: ";
    Date = DecreaseDateByXYearsFaster(Date,10);
    MyDate::PrintDate(Date);

    cout << "10.Decreasing One Decade is: ";
    Date = DecreaseDateByOneDecade(Date);
    MyDate::PrintDate(Date);

    cout << "11.Decreasing 10 Decades is: ";
    Date = DecreaseDateByXDecades(Date,10);
    MyDate::PrintDate(Date);

    cout << "12.Decreasing 10 Decades(faster) is: ";
    Date = DecreaseDateByXDecadesFaster(Date,10);
    MyDate::PrintDate(Date);

    cout << "13.Decreasing One Century is: ";
    Date = DecreaseDateByOneCentury(Date);
    MyDate::PrintDate(Date);

    cout << "14.Decreasing One Millennium is: ";
    Date = DecreaseDateByOneMillennium(Date);
    MyDate::PrintDate(Date);
}



