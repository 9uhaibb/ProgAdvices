#include<iostream>
#include<string>
#include<vector>

using namespace std;

/* how string.replace() works
replace (from position(number), No. of chars to replace, replace to)
*/

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

int main ()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country.";

    string StringToReplace = "Jordan";
    string ReplaceTo = "Palestine";

    cout << "Original String :\n" << S1 << endl;

    cout << "\n\nString after replace : \n"
    << ReplaceWordsInString(S1, StringToReplace, ReplaceTo);



}