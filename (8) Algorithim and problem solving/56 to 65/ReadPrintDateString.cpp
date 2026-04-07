#include <iostream>
#include "MyDate.h"
#include <vector>

using namespace std;
using namespace MyDate;
/*
string ReadStringDate (string Massege)
{
    string DateString;

    cout << Massege;
    getline(cin >> ws, DateString);
    return DateString;
}

vector <string>  SplitString (string String, string Delim)
{
    vector <string> vString;

    short Position = 0;
    string sWord;

    while((Position = String.find(Delim)) != std::string::npos)
    {
        sWord = String.substr(0, Position);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        String.erase(0, Position + Delim.length());
    }

    // now there still the last word and the loop can't reach it.
    if (String != "")
    {
        vString.push_back(String); // added it to the vector
    }
    return vString;
}

sDate StringToDateStructure (string DateString)
{
    sDate Date;
    vector <string> vDate = SplitString(DateString,"/");

    Date.Day = stoi (vDate[0]);
    Date.Month = stoi (vDate[1]);
    Date.Year = stoi (vDate[2]);

    return Date;
}

string sDateToString (sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
*/
int main ()
{
    string DateString = ReadStringDate ("Enter Date dd/mm/yyyy ? ");

    sDate Date = StringToDateStructure (DateString);
    cout << endl;

    cout << "Day: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

    cout << "\nYou Entered: " << sDateToString(Date);

    system("pause>0");
    return 0;
}