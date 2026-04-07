#include<iostream>

#include"clsDate.h"

using namespace std;

int main ()
{
    
    clsDate Date = clsDate(20, 9, 2005);
    // cout << Date.DaysFromTheBeginingOfTheYear() << endl;    

    // clsDate current = clsDate();
    // cout << Date.GetDifferenceInDays(current);

    cout << "Date Before increase: ";
    Date.Print();

    cout << "Date After add one Year: ";
    Date.IncreaseDateByOneYear();
    Date.Print();
    





    

}