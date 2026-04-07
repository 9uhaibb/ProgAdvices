// print first letter of each word (Upper and Lower Case)

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

void PrintFirstLetterOfEachWord (string S1)
{
    bool isFirstLetter = true; /* true = First letter, false = Not a first letter (' ')*/

    cout << "\n First Letters of this string: \n";

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter/*true*/)
        {
            cout << S1[i] << endl;
        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
        /*if (S1[i] == ' ')
            isFirstLetter = true;
        else 
            isFirstLetter = false;*/
    }
}

int main ()
{
    PrintFirstLetterOfEachWord(ReadString());
}