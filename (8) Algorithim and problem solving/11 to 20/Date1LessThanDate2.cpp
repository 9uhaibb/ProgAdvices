#include <iostream>

using namespace std;

struct sDate
{
    short Day,Month,Year;
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
    Date.Day = ReadDay();
    Date.Month = ReadMonth ();
    Date.Year = ReadYear();
    return Date;
}
bool isDate1BeforeDate2 (sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? ((Date1.Day < Date2.Day) ? true : false) : false) : false);
}
int main ()
{
    cout << "Enter Date 1:\n";
    sDate Date1 = ReadFullDate();
    cout << "Enter Date 2:\n";
    sDate Date2 = ReadFullDate();

    if (isDate1BeforeDate2(Date1, Date2))
        cout << "Yes, Date 1 is less then Date 2\n";
    else
        cout << "No, Date 1 is not less then Date 2\n";
}
