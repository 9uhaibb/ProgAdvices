#include <iostream>
#include"clsInputValidate.h"

int main ()
{
    cout << clsInputValiDate::IsNumberBetween(3, 1, 5) << endl;
    cout << clsInputValiDate::ReadNumber <int> ("Invalid, Try again: ") << endl;
    cout << clsInputValiDate::ReadNumberBetween <int> (1, 5, "Invalid, Try again: ") << endl;
    cout << clsInputValiDate::ReadString() << endl;
}