// a Prog to join vector of strings into a one string
// with seperators

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

string JoinString (vector <string> vString, string Delim)
{
    string S1 ="";
    for (string &S : vString)
    {
        S1 += (S + Delim);
    }
    return S1.substr(0, S1.length() - Delim.length());
}

string JoinString (string Arr[], int ArrLength, string Delim)
{
    string S1 ="";
    for (int i = 0; i < ArrLength; i++)
    {
        S1 += Arr[i] + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}

int main ()
{
    vector <string> vString = {"Mohammad"," Suhaib"," Ahmad"};
    string ArrNames [3] = {"Mohammad"," Suhaib"," Ahmad"};

    cout << "Vector After Join:\n";
    cout << JoinString(vString, " ");

    cout << "Array After Join:\n";
    cout << JoinString(ArrNames, 3, " ");
}