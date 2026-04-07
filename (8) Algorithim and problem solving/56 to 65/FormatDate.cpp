#include <iostream>
#include "MyDate.h"

using namespace std;
using namespace MyDate;
/*
string ReplaceWordsInString (string String, string StringToReplace, string ReplaceTo)
{
    short pos = String.find(StringToReplace);

    while (pos != std::string::npos)
    {
        String = String.replace(pos, StringToReplace.length(),ReplaceTo);

        pos = String.find(StringToReplace); // search again
    }
    return String;
}

string FormatDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormatedDate = "";
    FormatedDate = ReplaceWordsInString(DateFormat, "dd", to_string(Date.Day));
    FormatedDate = ReplaceWordsInString(FormatedDate, "mm", to_string(Date.Month));
    FormatedDate = ReplaceWordsInString(FormatedDate, "yyyy", to_string(Date.Year));

    return FormatedDate;
}
*/
int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    sDate Date = StringToDate(DateString);
    cout << "\n"
         << FormatDate(Date) << "\n";
    cout << "\n"
         << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n"
         << FormatDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n"
         << FormatDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n"
         << FormatDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n"
         << FormatDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";
    system("pause>0");
    return 0;
}