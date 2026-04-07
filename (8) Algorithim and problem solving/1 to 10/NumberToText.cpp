#include <iostream>
using namespace std;

int ReadNumber ()
{
    int n;
    cout << "Enter a number(without spaces)? ";
    cin >> n;
    return n;
}

string NumberToText (int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight"
                        , "Nine", "Ten", "Twilve", "Eleven", "Thirteen", "Fourteen", "Fifteen"
                        , "Sixteen", "Seventeen", "Eighteen", "Ninteen"};
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twinty", "Thirty", "Fourty", "Fifty"
                        , "Sixty", "Seventy", "Eighty", "Ninty"};
        return arr[Number / 10] + " " + NumberToText(Number % 10); // suppose number = 21
    //  return arr[21 / 10] + " " + NumberToText (21 % 10);
    //  return  arr [2] + " " + NumberToText (1)
    //  return Twinty One
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText (Number % 100); // suppose number = 120
//      return One Hundred + NumberToText (120 % 100)
//      return One Hundred + NumberToText (20)
//      return One Hundred + Twinty
    }
    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText (Number % 100); // suppose number = 250
//      return NumberToText(250 / 100) + "Hundreds " + NumberToText (250 % 100)
//      return NumberToText(2) + "Hundreds " + NumberToText (50)
//      return Two + Hundreds +  Fifty
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText (Number % 1000); 
    }
    if (Number >= 2000 && Number <= 999999) // 999 999
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText (Number % 1000); 
    }
    if (Number >= 1000000 && Number <= 1999999) // 1 999 999
    {
        return "One Million " + NumberToText (Number % 1000000); 
    }
    if (Number >= 2000000 && Number <= 999999999) // 999 999 999
    {
        return NumberToText(Number / 1000000) + "Thousands " + NumberToText (Number % 10000000); 
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText (Number % 1000000000);
    }
    else 
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText (Number % 1000000000); 
    }
}
int main ()
{
    int Number = ReadNumber ();
    cout << NumberToText (Number);
    system("pause>0");
    return 0;
}