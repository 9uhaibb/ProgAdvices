#include <iostream>
#include <string>

using namespace std;

struct strInfo // user informations
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};

void ReadInfo(strInfo &Info) // to let info in Read the same as info in print
{                            // if i didint put it info in Read != info in print so the output will be without 
                             // what user entered

    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;

    cout << "Please enter LastName?\n";
    cin >> Info.LastName;

    cout << "Please enter Age?\n";
    cin >> Info.Age;

    cout << "Please enter Phone?\n";
    cin >> Info.Phone;

}
void PrintInfo(strInfo Info) 
{

    cout << "\n**********************************\n";

    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;

    cout << "\n**********************************\n";


}

void ReadPersonsInfo(strInfo Persons[100], int &n)
{
    
    cout << "How many person ? ";
    cin >> n; // عدد عناصر المصفوفة (عدد الاشخاص)

    for (int i = 0; i<= (n-1); i++) //create array from 0 to n-1
    {
        cout << "Please enter person "<< i+1 << "info" << endl;
        ReadInfo(Persons[i]);
    }
}
void PrintPersonsInfo(strInfo Persons[100], int &n)
{
    for (int i = 0; i <= (n-1); i++ )
    {
     cout << "**********************************\n";
     PrintInfo(Persons[i]);

    }
}

int main()
{
    int n;
    strInfo Persons[100];

    ReadPersonsInfo(Persons, n);
    PrintPersonsInfo(Persons, n);
   
    return 0;
}