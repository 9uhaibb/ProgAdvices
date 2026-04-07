#include<iostream>
using namespace std;

enum enMounthOfYear {
    Januray = 1, February = 2, March = 3, April = 4, May = 5, June = 6,
    July = 7 , August = 8 , September = 9, October = 10, November = 11, 
    December = 12
};

int ReadNumberInRange (string massege, int from, int to)
{
    int number = 0;
    do 
    {
        cout << massege << endl;
        cin >> number;
    } while (number < from || number > to);
}

enMounthOfYear ReadMounth ()
{
    return (enMounthOfYear)ReadNumberInRange("Enter Mounth Number?",1,12);
}

string PrintMounth (enMounthOfYear mounth)
{
    switch (mounth)
    {
        case enMounthOfYear::Januray:
            return "its January.\n";
        case enMounthOfYear::February:
            return "its February.\n";
        case enMounthOfYear::March:
            return "its March.\n";
        case enMounthOfYear::April:
            return "its April.\n";
        case enMounthOfYear::May:
            return "its May.\n";
        case enMounthOfYear::June:
            return "its June.\n";
        case enMounthOfYear::July:
            return "its July.\n";
        case enMounthOfYear::August:
            return "its August.\n";
        case enMounthOfYear::September:
            return "its September.\n";
        case enMounthOfYear::October:
            return "its October.\n";
        case enMounthOfYear::November:
            return "its November.\n";
        case enMounthOfYear::December:
            return "its December.\n";
        
    }
}

int main ()
{
   cout << PrintMounth(ReadMounth());
}