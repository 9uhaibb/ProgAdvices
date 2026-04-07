# include <iostream>

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
bool isLeapYear (short Year)
{
    return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth (short Year, short Month)
{
    if (Month > 12 || Month < 1)
        return 0;
    int arrNumberOfDays [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];
}

int main ()
{
    short Year = ReadYear ();
    short Month = ReadMonth ();

    cout << "Number of Days in Month[" << Month
     << "] in Year[" << Year << "]: " << NumberOfDaysInMonth(Year, Month)<< endl;
}