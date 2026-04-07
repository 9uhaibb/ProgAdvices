#include <iostream>
#include "MyDate.h"

using namespace MyDate;
using namespace std;
/* i added it to MyDate library
bool isDate1AfterDate2 (sDate Date1, sDate Date2)
{
    return (!isDate1BeforeDate2(Date1, Date2) && !is2DatesEqual(Date1, Date2));
}
*/

int main ()
{
    cout << "Enter Date 1:\n";
    sDate Date1 = ReadFullDate();

    cout << "Enter Date 2:\n";
    sDate Date2 = ReadFullDate();

    if (isDate1AfterDate2 (Date1, Date2))
        cout << "Yes, Date 1 is After Date 2" << endl;
    else 
        cout << "No, Date 1 is Not After Date 2" << endl;
}

