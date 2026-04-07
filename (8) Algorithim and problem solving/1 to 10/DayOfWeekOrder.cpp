/*
a = [(14 - month) / 2]
y = year - a
m = month + 12a - 2

d = (day + y  + [y / 4] + [y / 100] + [y / 400] + [31m / 12]) % 7
the value of d is 0 for sunday, 1 for monday, etc

1)  print date: x/x/xxxx
2) day order : x
3) day name : x
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

short DayOfWeekOrder (short Day, short Month, short Year)
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
int main ()
{
    short Year = ReadYear();
    short Month = ReadMonth ();
    short Day = ReadDay ();
    short DayOrder = DayOfWeekOrder (Day, Month, Year);

    cout << "Date: "<< Day << "/" << Month << "/" << Year;
    cout << "\nDay Order: " << DayOrder;
    cout << "\nDay Name: " << DayShortName(DayOrder);

    system("pause>0");
    return 0;
}