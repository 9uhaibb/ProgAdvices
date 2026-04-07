#ifndef MYDateLIBRARY_H
#define MYDateLIBRARY_H
#include <iostream>
#include <vector>
using namespace std;
namespace MyDate
{
    short ReadYear()
    {
        cout << "Enter Year: ";
        short n;
        cin >> n;
        return n;
    }
    short ReadMonth()
    {
        cout << "Enter Month: ";
        short n;
        cin >> n;
        return n;
    }
    short ReadDay()
    {
        cout << "Enter Day: ";
        short n;
        cin >> n;
        return n;
    }
    bool isLeapYear(short Year)
    {
        return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
    }
    struct sDate
    {
        short Day, Month, Year;
    };
    sDate ReadFullDate()
    {
        sDate Date;
        Date.Day = ReadDay();
        Date.Month = ReadMonth();
        Date.Year = ReadYear();
        return Date;
    }
    void PrintDate(sDate Date)
    {
        cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    }
    short NumberOfDaysInMonth(short Year, short Month)
    {
        if (Month > 12 || Month < 1)
            return 0;
        int arrNumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];
    }
    
    bool isLastDayInMonth(sDate Date)
    {
        return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
    }
    bool isLastMonthInYear(sDate Date)
    {
        return (Date.Month == 12);
    }
    bool isDate1BeforeDate2(sDate Date1, sDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? ((Date1.Day < Date2.Day) ? true : false) : false) : false);
    }

    string MonthShortName(short MonthNumber)
    {
        string Months[12] = {"Jan", "Feb", "Mar",
                             "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep",
                             "Oct", "Nov", "Dec"};
        return (Months[MonthNumber - 1]);
    }
    string DayShortName(short DayIndex)
    {
        // Gregorian:
        // 0: Sun, 1 : Mon,...etc
        string arrDayName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return arrDayName[DayIndex];
    }
    sDate IncreaseDateByOneDay(sDate Date)
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
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }
        return Date;
    }
    short DayOfWeekOrder(short Day, short Month, short Year)
    {
        int a = 0, d = 0, m = 0, y = 0;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        // Gregorian:
        // 0: Sun, 1 : Mon,...etc
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    sDate GetSystemDate()
    {
        sDate Date;
        time_t t = time(0);
        tm *now = localtime(&t);
        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;
        return Date;
    }
    int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        while (isDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days : Days;
    }
    // 1.IncreaseDateByXDays
    sDate IncreaseDateByXDays(sDate Date, short X)
    {
        for (int i = 1; i <= X; i++)
            Date = IncreaseDateByOneDay(Date);
        return Date;
    }

    // 2. IncreaseDate by one week
    sDate IncreaseDateByOneWeek(sDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    // 3.IncreaseDateByXWeeks
    sDate IncreaseDateByXWeeks(sDate Date, short Weeks)
    {
        for (int i = 1; i <= Weeks; i++)
            Date = IncreaseDateByOneWeek(Date);
        return Date;
    }

    // 4.IncreaseDateByOneMonth
    sDate IncreaseDateByOneMonth(sDate Date)
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
    sDate IncreaseDateByXMonths(sDate Date, short X)
    {
        for (int i = 1; i <= X; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    // 6.IncreaseDateByOneYear
    sDate IncreaseDateByOneYear(sDate Date)
    {
        Date.Year += 1;
        return Date;
    }

    // 7. IncreaseDateByXYears
    sDate IncreaseDateByXYears(sDate Date, short Years)
    {
        for (int i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    // 8. add x years faster
    sDate IncreaseDateByXYearsFaster(sDate Date, short Years)
    {
        Date.Year += Years;
        return Date;
        ;
    }

    // 9.IncreaseDateByOneDecade
    sDate IncreaseDateByOneDecade(sDate Date)
    {
        Date.Year += 10;
        return Date;
    }

    // 10.IncreaseDateByXDecades
    sDate IncreaseDateByXDecades(sDate Date, short Decades)
    {
        for (int i = 1; i <= Decades * 10; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    // 11.IncreaseDateByXDecades faster
    sDate IncreaseDateByXDecadesFaster(sDate Date, short Decades)
    {
        Date.Year += Decades * 10;
        return Date;
    }

    // 12.IncreaseDateByOneCentury
    sDate IncreaseDateByOneCentury(sDate Date)
    {
        Date.Year += 100;
        return Date;
    }
    // 13.IncreaseDateByOneMillennium
    sDate IncreaseDateByOneMillennium(sDate Date)
    {
        Date.Year += 1000;
        return Date;
    }

    short DayOfWeekOrder(sDate Date)
    {
        short dayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return dayOrder;
    }
    void PrintCurrentDate(sDate Date)
    {
        cout << DayShortName(DayOfWeekOrder(Date)) << " , ";
        PrintDate(Date);
    }

    bool IsEndOfWeek(sDate Date)
    {
        return MyDate::DayOfWeekOrder(Date);
    }
    bool is2DatesEqual(sDate Date1, sDate Date2)
    {
        return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
    }
    bool IsWeekEnd(sDate Date)
    {
        return MyDate::DayOfWeekOrder(Date) == 5 || MyDate::DayOfWeekOrder(Date) == 6; // friday or satarday
    }

    bool IsBussinessDay(sDate Date)
    {
        return !IsWeekEnd(Date);
    }
    short DaysUntilTheEndOfWeek(sDate Date)
    {
        return 6 - MyDate::DayOfWeekOrder(Date);
    }
    short DaysUntilTheEndOfMonth(sDate Date)
    {
        sDate EndOfMonthDate;
        EndOfMonthDate.Day = MyDate::NumberOfDaysInMonth(Date.Year, Date.Month);
        EndOfMonthDate.Month = Date.Month;
        EndOfMonthDate.Year = Date.Year;
        return MyDate::GetDifferenceInDays(Date, EndOfMonthDate, true);
    }
    short DaysUntilTheEndOfYear(sDate Date)
    {
        sDate EndOfMonthDate;
        EndOfMonthDate.Day = 31;
        EndOfMonthDate.Month = 12;
        EndOfMonthDate.Year = Date.Year;
        return MyDate::GetDifferenceInDays(Date, EndOfMonthDate, true);
    }

    short VacationDays(sDate vacationStart, sDate vacationEnd)
    {
        short vacationDays = 0;

        while (isDate1BeforeDate2(vacationStart, vacationEnd))
        {
            if (!IsWeekEnd(vacationStart))
                vacationDays++;
            vacationStart = IncreaseDateByOneDay(vacationStart);
        }
        return vacationDays;
    }
    bool isDate1AfterDate2(sDate Date1, sDate Date2)
    {
        return (!isDate1BeforeDate2(Date1, Date2) && !is2DatesEqual(Date1, Date2));
    }
    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    enDateCompare CompareDates(sDate Date1, sDate Date2)
    {
        if (isDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;
        else if (isDate1AfterDate2(Date1, Date2))
            return enDateCompare::After;
        else
            return enDateCompare::Equal;
    }
    void SwapDates(sDate &Date1, sDate &Date2)
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
    struct sPeriod
    {
        sDate StartDate;
        sDate EndDate;
    };
    /*
    if Period 1 End before Period 2 Start, so there is no overlap
    id Period 1 Strat After Period 2 End, so there is no overlap
    */
    bool isOverlapPeriods(sPeriod Period1, sPeriod Period2)
    {
        return !(CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before || CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After);
    }

    sPeriod ReadPeriod()
    {
        sPeriod Period;
        cout << "\nEnter Start Date:\n\n";
        Period.StartDate = ReadFullDate();
        cout << "\nEnter End Date:\n\n";
        Period.EndDate = ReadFullDate();
        return Period;
    }
    int PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
    {
        return (GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay));
    }
    bool isDateWithinPeriod(sDate Date, sPeriod Period)
    {
        return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before || CompareDates(Date, Period.EndDate) == enDateCompare::After);
    }

    string ReadStringDate(string Massege)
    {
        string DateString;

        cout << Massege;
        getline(cin >> ws, DateString);
        return DateString;
    }

    vector<string> SplitString(string String, string Delim)
    {
        vector<string> vString;

        short Position = 0;
        string sWord;

        while ((Position = String.find(Delim)) != std::string::npos)
        {
            sWord = String.substr(0, Position);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            String.erase(0, Position + Delim.length());
        }

        // now there still the last word and the loop can't reach it.
        if (String != "")
        {
            vString.push_back(String); // added it to the vector
        }
        return vString;
    }

    sDate StringToDate(string DateString)
    {
        sDate Date;
        vector<string> vDate = SplitString(DateString, "/");

        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);

        return Date;
    }

    string sDateToString(sDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string ReplaceWordsInString(string String, string StringToReplace, string ReplaceTo)
    {
        short pos = String.find(StringToReplace);

        while (pos != std::string::npos)
        {
            String = String.replace(pos, StringToReplace.length(), ReplaceTo);

            pos = String.find(StringToReplace); // search again
        }
        return String;
    }

    string FormatDate(sDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormatedDate = "";
        FormatedDate = ReplaceWordsInString(DateFormat, "dd", to_string(Date.Day));
        FormatedDate = ReplaceWordsInString(FormatedDate, "mm", to_string(Date.Month));
        FormatedDate = ReplaceWordsInString(FormatedDate, "yyyy", to_string(Date.Year));

        return FormatedDate;
    }

}
#endif