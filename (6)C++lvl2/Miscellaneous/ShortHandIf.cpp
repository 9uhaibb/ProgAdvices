#include <iostream>
#include "InputsLib.h"

using namespace std;

void ShortHandIf()
{
    // condition ? expression (True) : expression (False)

    int Mark = 90;
    string result;

    // Short hand if
    result = (Mark >= 50) ? "Pass" : "Fail";
    cout << result << endl;

    (Mark >= 50) ? cout << "Pass" : cout << "Fail";
    (Mark >= 50) ? cout << "Pass" : (Mark >= 50) ? cout << "Pass"
                                                 : cout << "Fail";

    // you can also call a function rather than Pass or Fail
}

void PositiveNegativeNumber(int number)
{
    (number >= 0) ? cout << "Positive" : cout << "Negetive";
}
void PositiveNegativeNumberOrZero(int number)
{
    (number == 0) ? cout << "Zero" : ((number >= 0) ? cout << "Positive" : cout << "Negetive");
}

int main()
{
    cout << "program 1: \n";

    int Number = InputsLib::ReadNumber();
    PositiveNegativeNumber(Number);

    cout << "\nProgram 2: \n";

    int Number2 = InputsLib::ReadNumber();

    PositiveNegativeNumberOrZero(Number2);
}