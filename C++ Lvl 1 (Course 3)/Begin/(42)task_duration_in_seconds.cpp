#include <iostream>

using namespace std;

int main ()
{
    /*calculate task duration in seconds and print it on screen
    user enter task duration in days, hours,
    minutes, seconds*/

    int day, hours, minutes, seconds;
    cout << "enter tsdk duration time in :\n";
    cout << "days : ";
    cin >> day;
    cout << "hours : ";
    cin >> hours;
    cout << "minutes : ";
    cin >> minutes;
    cout << "seconds : ";
    cin >> seconds;

    long long day_n_seconds= day*24*60*60;
    long long hours_n_seconds= hours*60*60;
    long long minutes_n_seconds= minutes*60;

    long long total_time= day_n_seconds + hours_n_seconds + minutes_n_seconds + seconds;

    cout << "total time in seconds is : " << total_time << endl;
}