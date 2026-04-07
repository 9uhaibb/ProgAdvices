#include <iostream>
using namespace std;

struct sDate
{
    short Day, Month, Year;
};
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
sDate ReadFullDate ()
{
    sDate Date;
    Date.Day = ReadDay ();
    Date.Month = ReadMonth ();
    Date.Year = ReadYear();
    return Date;
}

bool is2DatesEqual (sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

int main ()
{
    cout << "Date 1: \n";
    sDate Date1 = ReadFullDate();
    cout << "Date 2: \n";
    sDate Date2 = ReadFullDate();

    if (is2DatesEqual(Date1, Date2))
        cout << "yes, 2 dates are equal\n";
    else 
        cout << "no, 2 dates are'nt equal\n";
    
}