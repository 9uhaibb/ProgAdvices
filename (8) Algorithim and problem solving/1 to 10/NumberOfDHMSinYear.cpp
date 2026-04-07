#include <iostream>

using namespace std;

short ReadNumber ()
{
    cout << "Enter Year: ";
    short n ; cin >> n; return n;
}

bool isLeapYear (short Year)
{
    return (Year % 400 ==0 || Year % 4 ==0 && Year % 100 != 0);
}

short NumberOfDaysInYear (short Year)
{
    return isLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear (short Year)
{
    return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear (short Year)
{
    return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear (short Year)
{
    return NumberOfMinutesInYear (Year) * 60;
}

int main ()
{
    short Year = ReadNumber ();

    cout << "Number Of Days in Year [" << Year << "]: " << NumberOfDaysInYear(Year) << endl;
    cout << "Number Of Hours in Year [" << Year << "]: " << NumberOfHoursInYear(Year) << endl;
    cout << "Number Of Minutes in Year [" << Year << "]: " << NumberOfMinutesInYear(Year) << endl;
    cout << "Number Of Seconds in Year [" << Year << "]: " << NumberOfSecondsInYear(Year) << endl;
    system("pause>0");
    return 0;
}