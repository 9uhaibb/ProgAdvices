#include <iostream>
using namespace std;

void PrintAAAToZZZ ()
{
    cout << endl;
    string word = "";
    for (int i = 65; i <= 90 ; i++)
    {
        for (int j = 65 ; j <= 90; j++)
        {
            for (int k = 65; k <= 90 ;k++)
            {
                word = word + char(i); // A     A   ...
                word = word + char(j); // AA    AA
                word = word + char(k); // AAA   AAB

                cout << word << endl;
                word = "";             // make it empty again
            }

        }
    cout << "______________________\n";

    }
}

int main ()
{
    PrintAAAToZZZ();
}