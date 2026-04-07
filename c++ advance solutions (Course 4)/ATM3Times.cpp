#include<iostream>
using namespace std;

string ReadPinCode ()
{
    string pincode;
    cout << "Enter PIN Code?\n";
    cin >> pincode;
    return pincode;
}
bool login ()
{
    string pincode;
    int counter = 3;
    do 
    {
        counter--;
        pincode = ReadPinCode();
        if (pincode == "1234")
        {
            return 1; // exit the function and return true
        }
        else 
        {
            system("color 4F"); // screen GREEN
            cout << "\nWrong PIN, You have " << counter << " Times left.\n";
        }
    } while (counter >= 1 && pincode != "1234");
    return 0; // when you reach here this means the function
}

int main ()
{
    if (login () == true)
    {
        system("color 2F"); // turn screen green
        cout << "Your Accont Balance is " << 7500 << endl;
    }
    else
    {
        cout << "Your Card Bloked, Please Call the Bank." << endl;
    }
}