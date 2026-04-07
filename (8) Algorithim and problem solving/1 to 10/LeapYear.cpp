/*note :
All years wich are perfectly divisible by 4 and not divisible by 100 are leap years ,
also a year is leap only if it perfectly divisible by 400.

leap year (366D)   Not leap year(365D)
1968                1971
2004                2006
2012                2010
1200                1700
1600                1800
2000                1900
*/
#include <iostream>
using namespace std;

short ReadNumber ()
{
    short n;
    cout << "Enter a year: ";
    cin >> n;
    return n;
}

bool isLeapYear (short Year)
{
    if (Year % 400 == 0)
        return true;
    else if (Year % 4 == 0 && Year % 100 != 0)
        return true;
    else 
        return false;
}
int main ()
{
    short Year = ReadNumber();
    if (isLeapYear(Year))
        cout << Year << " is Leap Year.\n";
    else 
        cout << Year << " is Not Leap Year.\n";
    system("pause>0");
    return 0;
}