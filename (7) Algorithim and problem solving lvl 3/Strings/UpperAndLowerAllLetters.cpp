// Read string then upper and lower all letters,
// then print them

/*F :
    1- ReadString. 2- Upper all letters, 3- Lower all letters*/

#include<iostream>
#include<string>

using namespace std;

string ReadString ()
{
    string S1;
    cout << "Enter String ?\n";
    getline(cin, S1);
    return S1;
}

string UpperAllString (string S1)
{
    for (int i = 0; i <= S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            S1[i] = toupper(S1[i]);
        }
    }
    return S1;
}

string LowerAllString (string S1)
{
        for (int i = 0; i <= S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
           S1[i] = tolower(S1[i]);
        }
    }
    return S1;
}

int main ()
{
    string S1 = ReadString();
    cout << "Orginal string : " << S1 << endl;
    cout << "Upper : " << UpperAllString(S1) << endl;
    cout << "Lower : " << LowerAllString (S1) << endl;

    system("pause>0");

}