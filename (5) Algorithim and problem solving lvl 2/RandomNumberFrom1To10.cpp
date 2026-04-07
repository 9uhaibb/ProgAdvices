#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int RandomNumber (int From,int To)
{
    int randNumber = rand () % (To - From + 1) + From;
    return randNumber;
}

int main ()
{
    srand((unsigned)time(NULL));

    cout << endl << "***\n";
    cout <<" " << RandomNumber(1,10) << endl;
    cout <<" " << RandomNumber(1,10) << endl;
    cout <<" " << RandomNumber(1,10) << endl;
    cout << "***\n"; 
}