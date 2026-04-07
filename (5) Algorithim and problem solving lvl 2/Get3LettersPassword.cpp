#include <iostream>
using namespace std;

string ReadPassword (string massege)
{
    string Password ="";
    cout << massege << endl;
    cin >> Password;
    return Password;
}

bool PrintAAAToZZZ (string OrginalPAssword)
{
    cout << endl;
    string word = "";
    int counter = 0;
for (int i = 65; i <= 90 ; i++)
    {
        for (int j = 65 ; j <= 90; j++)
        {
            for (int k = 65; k <= 90 ;k++)
            {
                counter ++;
                word = word + char(i); // A     A   ...
                word = word + char(j); // AA    AA
                word = word + char(k); // AAA   AAB
                
                if (counter <=9)
                {
                cout << "Trial  [" << counter <<"] : "  << word << endl;

                    if (word == OrginalPAssword)
                    {
                        cout << "\nPssword is " << word << endl;
                        cout << "Found After " << counter << " Trials.";
                        return true;
                    }
                }
                else 
                {
                                    cout << "Trial [" << counter <<"] : "  << word << endl;

                    if (word == OrginalPAssword)
                    {
                        cout << "\nPssword is " << word << endl;
                        cout << "Found After " << counter << " Trials.";
                        return true;
                    }

                }

                word = "";             // make it empty again
            }
        }
    
    }

}

int main ()
{
    PrintAAAToZZZ(ReadPassword("Enter Password? (in Capital)"));
}