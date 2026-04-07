#pragma warning (disable : 4996)

#include <iostream>
#include<ctime>

using namespace std;

int main ()
{
    // Time now is : 
    time_t TimeNow = time(0);

    // convert Time into string, inside DateTime using pointer
    char * StringDateTime = ctime(&TimeNow); // u can't do it with string
    cout << "Local Date and time is : " << StringDateTime << endl;

    // Now convert to tm struct for UTC (universal time) date/time
    // tm is a structure
    tm * GlobalTime = gmtime(&TimeNow);

    StringDateTime = asctime (GlobalTime); // asctime used cuz tm type cannnot be stored in char type
    cout << "UTC Date and Time is : " << StringDateTime << endl;

    

}