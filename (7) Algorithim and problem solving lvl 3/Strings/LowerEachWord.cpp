// read string then uppercase the first letter of each word in that string;

/*F :
    read string, 2- PrintStringwithUppercases*/

#include<iostream>
#include<string>

using namespace std;

string ReadString ()
{
    string S1;
    cout << "Enter string: \n";
    getline(cin, S1);

    return S1;
}

string LowerFirstLetterOfEachWord (string S1)
{
    bool isFirstLetter = true;
    for (int l = 0; l < S1.length(); l++)
    {
        if (isFirstLetter == true && S1[l] != ' ')
        {
            S1[l] = tolower(S1[l]);
        }
        isFirstLetter = (S1[l] == ' ' ? true : false);
    }
    return S1;
}

int main ()
{
    string S1 = ReadString();
    cout << "\nString after convertion: \n";

    S1 = LowerFirstLetterOfEachWord(S1);
    cout << S1 << endl;
}
