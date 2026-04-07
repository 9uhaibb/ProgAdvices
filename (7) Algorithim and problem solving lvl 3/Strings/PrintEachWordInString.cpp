#include<string>
#include<iostream>

/*  1- find("xxx" || 'x' ) ===> find word or char in  string
    2- substr(from(int pos), to(int pos)) ===> select part of string
    3- erase(from(int pos), to(int pos))  ===>  delete part of string
    4- push_back / pop_back
    5- length
    6- at
    7-insert
    8- append
    9- clear
    10- empty


*/

using namespace std;

string ReadString ()
{
    string S1;
    cout << "Enter String: ";
    getline(cin, S1);
    return S1;
}

void PrintEachWordInString (string S1)
{
    short position = 0;
    string Delim = " ";
    string sWord;

    while ((position = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, position);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, position + Delim.length());
    }
    // the last word
    if (!S1.empty())
    {
        cout << S1 << endl;
    }
}
int main ()
{

    PrintEachWordInString (ReadString());

    system("pause>0");
}
