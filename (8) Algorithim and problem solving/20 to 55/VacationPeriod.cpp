#include <iostream>
#include"MyDate.h"

using namespace MyDate;
using namespace std;

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

int main ()
{
    cout << "Vacation Starts:\n";
    sDate vacationStarts = MyDate::ReadFullDate();
    cout << "\nVacation Ends:\n";
    sDate vacationEnds = MyDate::ReadFullDate();

    cout << "\nVacation From:";
    MyDate::PrintCurrentDate(vacationStarts);

    cout << "Vacation To:";
    MyDate::PrintCurrentDate(vacationEnds);

    cout << "\n\nActual Vacation Days is: " << VacationDays(vacationStarts, vacationEnds);
    return 0;
}