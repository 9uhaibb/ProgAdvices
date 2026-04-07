#include<iostream>
using namespace std;

struct stTaskDuration 
{int Days, Hours, Minutes, Seconds;}; // to return them all at once

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

stTaskDuration ReadTaskDuration ()
{
    stTaskDuration TaskDuration;
    TaskDuration.Days = ReadPositiveNumber("Enter Days?");
    TaskDuration.Hours = ReadPositiveNumber ("Enter Hours?");
    TaskDuration.Minutes = ReadPositiveNumber("Enter Minutes?");
    TaskDuration.Seconds = ReadPositiveNumber ("Enter Seconds?");

    return TaskDuration;
}

int TaskDuratinInSeconds (stTaskDuration TaskDuration)
{
    int DurationInSeconds = 0;
    DurationInSeconds = TaskDuration.Days * 24 * 60 * 60;
    DurationInSeconds += TaskDuration.Hours * 60 * 60;
    DurationInSeconds += TaskDuration.Minutes * 60;
    DurationInSeconds += TaskDuration.Seconds;
    return DurationInSeconds;
}

int main ()
{
    cout << "\nTask Duration in Seconds is " << TaskDuratinInSeconds(ReadTaskDuration());
}