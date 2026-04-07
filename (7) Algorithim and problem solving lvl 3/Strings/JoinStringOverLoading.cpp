// Same 39, but use function overloading
// Function overloading: create +1 functions with the same name 
//but with differant parameters


// vector finctions:
// .push_back => add element
// .pop_back => delete last element
// .front() => first element
// .back() => last element
// .size() => return the number of elements
// .capaticy => check over all capaticy of a vector
// .empty => return true if empty

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string JoinString(vector <string> vString, string Delim)
{
    string FinalString = "" ;
    for (string &s : vString)
    {
        FinalString += s + Delim;
    }

    return FinalString.substr(0, FinalString.length()- Delim.length()) + ".";
     // return the string without the last delim
}

string JoinString(string ArrString[],short ArrLegth, string Delim)
{
    string FinalString = "";
    for (int i = 0; i < ArrLegth /*0 to 2 inside the array*/; i++)
    {
        FinalString += ArrString[i] + Delim;
    }
    return FinalString.substr(0, FinalString.length() - Delim.length()) + ".";
}

int main ()
{
    vector <string> vString ={"Suhaib", "Ahmad", "Omar"};
    string ArrStrings[] = {"Suhaib", "Ahmad", "Omar"};

    cout <<"\nVector after join :\n"
    << JoinString (vString, ", ");

    cout <<"\n\nArray after join :\n"
    << JoinString(ArrStrings,3 , ", ");


}