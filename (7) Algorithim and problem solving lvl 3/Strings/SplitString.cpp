// Read string and seperator then make a function to split each word in vector.
// then print number of tokens(words) and each word

// vector finctions:
// .push_back => add element
// .pop_back => delete last element
// .front() => first element
// .back() => last element
// .size() => return the number of elements
// .capaticy => check over all capaticy of a vector
// .empty => return true if empty

#include<iostream>
#include<vector>
#include"StringCharLib.h"
#include<string>

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


int main ()
{
    system("pause>0");
}