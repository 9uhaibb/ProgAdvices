#include<iostream>
#include<string>
#include<vector>

using namespace std;

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

string LowerAllLetters (string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
} 

string JoinString(vector <string> vString, string Delim)
{
    string FinalString = "" ;
    for (string &s : vString)
    {
        FinalString += s + Delim;
    }

    return FinalString.substr(0, FinalString.length()- Delim.length())  ;
     // return the string without the last delim
}

string ReplaceWordsInStringUSingSplit (string String, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
    vector <string> vString = SplitString(String, " ");

    for (string& s : vString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }
        else // MatchCase = false (regret letters cases)
        {
            if (LowerAllLetters(s) == LowerAllLetters(StringToReplace))
            {
                s = ReplaceTo;
            }
        }
    }
    String = JoinString(vString," ");
    return String;
}

int main ()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country.";

    string StringToReplace = "jordan";
    string ReplaceTo = "Palestine";

    cout << "Original String :\n" << S1 << endl;

    cout << "\n\nString after replace(with match cases) : \n"
    << ReplaceWordsInStringUSingSplit(S1, StringToReplace, ReplaceTo);

    cout << "\n\nString after replace(without match cases) : \n"
    << ReplaceWordsInStringUSingSplit(S1, StringToReplace, ReplaceTo, false);

}