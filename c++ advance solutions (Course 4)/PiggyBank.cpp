#include<iostream>
using namespace std ;

struct stPiggyBankContent 
{
    int Pennies, Nickels, Dimes, Quarters, Dollars; 
};

stPiggyBankContent ReadPiggyBankContent ()
{
    stPiggyBankContent PiggyBankContent ;
    cout << "Enter Total Pennies: \n";
    cin >> PiggyBankContent.Pennies;
    cout << "Enter Total Nickels: \n";
    cin >> PiggyBankContent.Nickels;
    cout << "Enter Total Dimes: \n";
    cin >> PiggyBankContent.Dimes;
    cout << "Enter Total Quarters: \n";
    cin >> PiggyBankContent.Quarters;
    cout << "Enter Total Dollars: \n";
    cin >> PiggyBankContent.Dollars;
    return PiggyBankContent;
}

int CalculateTotalPennies (stPiggyBankContent PiggyBankContent)
{
    int TotalPennies = 0 ;
    TotalPennies = PiggyBankContent.Pennies * 1 + PiggyBankContent.Nickels * 5 +
    PiggyBankContent.Dimes * 10 + PiggyBankContent.Quarters * 25 +
    PiggyBankContent.Dollars * 100;
    return TotalPennies;
}

int main ()
{
    int TotalPennies = CalculateTotalPennies (ReadPiggyBankContent());
    cout << endl << "Total Pennies: " << TotalPennies;
    cout << endl << "Total Dollars: " << TotalPennies / 100 << endl; 
}