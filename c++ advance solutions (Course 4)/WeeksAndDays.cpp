#include<iostream>
using namespace std;

float ReadPositiveNumber (string massege)
{
    float number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    } while (number < 0);
    return number;
}

float HoursTODays (float NumberOFHours)
{
    return NumberOFHours / 24;
}

float HoursToWeeks (float NumberOFHours)
{
    return NumberOFHours / 24 / 7;
}

float DaysToWeek (float NumberOfDays)
{
    return NumberOfDays / 7;
}

int main ()
{
    float NumberOFHours = ReadPositiveNumber ("Enter number of hours?");
    float NumberOfDays = HoursTODays (NumberOFHours);
    float NumberOfWeeks = DaysToWeek (NumberOfDays);
    cout << endl;

    cout << "Total Hours: " << NumberOFHours << endl;
    cout << "Total Days: " << NumberOfDays << endl;
    cout << "Total Weeks: " << NumberOfWeeks << endl;

}