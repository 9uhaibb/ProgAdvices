#include<iostream>
#include"clsDate.h"

using namespace std;

int main ()
{
    clsDate Date;
    Date.Print();
    cout << endl;

    clsDate Date2 ("3/9/2025");
    Date2.Print();
    cout << endl;
    
    clsDate Date3 (3, 12, 2016);
    Date3.Print();
    cout << endl;

    cout << "\nDate from day order in year:\n";
    clsDate Date4 (4, 2016);
    Date4.Print();
    cout << endl;

    cout << Date2.isLastDayInMonth() << endl;
    cout << Date2.isLastMonthInYear() << endl;
    cout << clsDate::isLastMonthInYear(Date3) << endl;

    cout << Date2.isBeforeDate2(Date3) << endl;
    cout << Date2.MonthShortName() << endl;

   // Date2.year = 3;
                 
                 // Day index 1-7
   // cout << Date2.DayShortName() << endl;
    
    


    
}