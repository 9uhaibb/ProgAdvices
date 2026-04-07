// Read string then reverse its words

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ReadString ()
{
    string S1;
    cout << "Enter String: ";
    getline(cin, S1);
    return S1;
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

string ReverseString (string StringToReverse, string Delim)
{
    vector <string> vString ;
    string ReversedString = "";

    vString = SplitString(StringToReverse, Delim);

    // loop on the vector(from the last element) using iterator
    // Remmember: iterator is accessing vector elemnt using pointer

    vector <string> ::iterator iter = vString.end()/*يؤشر على نقطة ما بعد العنصر الاخير*/;

    while (iter != vString.begin())
    {
        --iter;
        ReversedString += *iter + Delim;
    }

    // at the end will be additional Delim,
    // we will delete it;

    ReversedString = ReversedString.substr(0, ReversedString.length() - 1); /* 1 is the delim */

    return ReversedString;
}

int main ()
{
    string S1 = ReadString();

    cout << "Reversed String: " << ReverseString(S1, " ");

    return 0;
}