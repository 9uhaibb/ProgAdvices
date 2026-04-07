#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;

/*
enum enDateCompare {Before = -1, Equal = 0, After = 1};

enDateCompare CompareDates (sDate Date1, sDate Date2)
{
    if (isDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    else if (isDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;
    else 
        return enDateCompare::Equal;
}
*/
int main ()
{
    cout << "Enter Date 1:\n";
    sDate Date1 = ReadFullDate();
    
    cout << "\nEnter Date 2:\n";
    sDate Date2 = ReadFullDate ();

    cout << "\nCompare Result: " << CompareDates (Date1, Date2);

}