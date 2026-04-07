/*
IncreasDateByOneDate (added before) done
1.IncreaseDateByXDays done
2.IncreaseDateByOneWeek done
3.IncreaseDateByXWeeks done 
4.IncreaseDateByOneMonth done 
5.IncreaseDateByXMonth done 
6.IncreaseDateByOneYear done 
7.IncreaseDateByXYears done 
8.IncreaseDateByXYearsFaster done (not sure)
9.IncreaseDateByOneDecade  done
10.IncreaseDateByXDecades done 
11.IncreaseDateByXDecadesFaster done (not sure)
12.IncreaseDateByOneCentury 
13.IncreaseDateByOneMillennium
*/
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

sDate IncreaseDateByOneDay (sDate Date)
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
// 1.IncreaseDateByXDays
sDate IncreaseDateByXDays (sDate Date, short X)
{
    for (int i = 1; i <= X; i++)
        Date = IncreaseDateByOneDay(Date);
    return Date;
}

// 2. IncreaseDate by one week
sDate IncreaseDateByOneWeek (sDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

// 3.IncreaseDateByXWeeks
sDate IncreaseDateByXWeeks (sDate Date, short Weeks)
{
    for (int i = 1; i <= Weeks; i++)
        Date = IncreaseDateByOneWeek(Date);
    return Date;
}

// 4.IncreaseDateByOneMonth
sDate IncreaseDateByOneMonth (sDate Date)
{
    if (isLastMonthInYear(Date))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else 
    {
        Date.Month++;
    }
    // different months have different Number of days
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;

}

// 5. IncreaseDateByXMonth
sDate IncreaseDateByXMonths (sDate Date, short X)
{
    for (int i = 1; i <= X; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

//6.IncreaseDateByOneYear
sDate IncreaseDateByOneYear (sDate Date)
{
    Date.Year += 1;
    return Date;
}

//7. IncreaseDateByXYears
sDate IncreaseDateByXYears (sDate Date, short Years)
{
    for (int i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

// 8. add x years faster
sDate IncreaseDateByXYearsFaster (sDate Date, short Years)
{
    Date.Year += Years;
    return Date;;
}

// 9.IncreaseDateByOneDecade
sDate IncreaseDateByOneDecade (sDate Date)
{
    Date.Year += 10;
    return Date;
}

// 10.IncreaseDateByXDecades
sDate IncreaseDateByXDecades (sDate Date, short Decades)
{
    for (int i = 1; i <= Decades * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

// 11.IncreaseDateByXDecades faster
sDate IncreaseDateByXDecadesFaster (sDate Date, short Decades)
{
    Date.Year += Decades * 10;
    return Date;
}

//12.IncreaseDateByOneCentury 
sDate IncreaseDateByOneCentury (sDate Date)
{
    Date.Year += 100;
    return Date;
}
//13.IncreaseDateByOneMillennium
sDate IncreaseDateByOneMillennium (sDate Date)
{
    Date.Year += 1000;
    return Date;
}

void PrintDate(sDate Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main ()
{
    sDate Date = ReadFullDate ();

    // 1.Adding one day
    cout << "\nDate After:\n";
    Date = IncreaseDateByOneDay(Date);
    cout << "1.Adding One Day is: ";
    PrintDate(Date);

    //2.Adding X Days
    Date = IncreaseDateByXDays (Date,10);
    cout << "2.Adding "<< 10 << " Days is: ";
    PrintDate(Date);

    //3. Adding One Week
    Date = IncreaseDateByOneWeek (Date);
    cout << "3.Adding One Week is: ";
    PrintDate(Date);

    //4. Adding X Week
    Date = IncreaseDateByXWeeks (Date, 10);
    cout << "4.Adding "<< 10 << " Weeks is: ";
    PrintDate(Date);

    // 5. Adding One Month 
    Date = IncreaseDateByOneMonth (Date);
    cout << "5.Adding One Month is: ";
    PrintDate(Date);

    // 6. Adding X Months 
    Date = IncreaseDateByXMonths (Date, 5);
    cout << "6.Adding 5 Months is: ";
    PrintDate(Date);

    // 7. Adding One Year 
    Date = IncreaseDateByOneYear (Date);
    cout << "7.Adding One Year is: ";
    PrintDate(Date);

    // 8. Adding One Year 
    Date = IncreaseDateByXYears (Date, 10);
    cout << "8.Adding 10 Years is: ";
    PrintDate(Date);

    // 9. Adding One Year 
    Date = IncreaseDateByXYearsFaster (Date, 10);
    cout << "9.Adding 10 Years (Faster) is: ";
    PrintDate(Date);

    // 10. Adding One Decade 
    Date = IncreaseDateByOneDecade (Date);
    cout << "10.Adding One Dacade is: ";
    PrintDate(Date);

    // 11. Adding x Decades
    Date = IncreaseDateByXDecades (Date, 10);
    cout << "11.Adding 10 Decades is: ";
    PrintDate(Date);

    // 12. Adding One Decade 
    Date = IncreaseDateByXDecadesFaster (Date, 10);
    cout << "12.Adding 10 Decades (Faster) is: ";
    PrintDate(Date);

    // 13. Adding One Century 
    Date = IncreaseDateByOneCentury (Date);
    cout << "13.Adding One Century is: ";
    PrintDate(Date);

    // 14. Adding One Millennium 
    Date = IncreaseDateByOneMillennium (Date);
    cout << "14.Adding One Millennium is: ";
    PrintDate(Date);

}