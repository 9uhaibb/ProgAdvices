#include<iostream>
#include<cmath>
using namespace std;

//user enter a number of seconds and the prog will change it
// to (Days,hours,minutes and seconds)

struct stTaskDuration 
{int Days , Hours , Minutes, Seconds ;}; 

int ReadPositiveNumber (string massege)
{
    int number = 0;
    do 
    {
    cout << massege << endl;
    cin >> number;
    } while (number < 0);
    return number;
}

stTaskDuration SecondsToTaskDuration (int TotalSeconds)
{
    stTaskDuration TaskDuration ;
    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHour = 60 * 60;
    const int SecondsPerMinute = 60;

    int Remainder = 0;
    TaskDuration.Days = floor(TotalSeconds / SecondsPerDay);
    Remainder = TotalSeconds % SecondsPerDay;

    TaskDuration.Hours = floor(Remainder / SecondsPerHour);
    Remainder = Remainder % SecondsPerHour;

    TaskDuration.Minutes = floor (Remainder / SecondsPerMinute);
    Remainder = Remainder % SecondsPerMinute;

    TaskDuration.Seconds = Remainder;

    return TaskDuration;
}

void PrintTaskDurationDetails (stTaskDuration TaskDuration)
{
    cout << endl;
    cout << TaskDuration.Days <<":"
         << TaskDuration.Hours << ":"
         << TaskDuration.Minutes << ":"
         <<TaskDuration.Seconds << endl;

}

int main ()
{
    int TotalSeconds = ReadPositiveNumber("Enter Number Of Seconds?");
    PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));
}