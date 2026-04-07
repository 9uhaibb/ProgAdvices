#include <iostream>
using namespace std;
/* Leap : Divisible perfectly by 400 
          Divisible perfectly by 4 and not Divisible perfectly by 100*/
short ReadNumber ()
{
    short n;
    cout << "Enter a year: ";
    cin >> n;
    return n;
}

bool isLeapYear (short Year)
{
    return(Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}
int main ()
{
    while (true)
    {
    short Year = ReadNumber();
    if (isLeapYear(Year))
        cout << Year << " is Leap Year.\n";
    else 
        cout << Year << " is Not Leap Year.\n";
    }
    system("pause>0");
    return 0;
}